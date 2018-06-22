#include "tableview.h"
#include <QFont>
#include <QColor>
#include <QBrush>

table_veiw::table_veiw(ctrl* c, QObject* parent) : QAbstractTableModel { parent }, _ctrl{ c }
{

}

table_veiw::~table_veiw()
{}

int table_veiw::rowCount(const QModelIndex & parent) const
{
    int number = this->_ctrl->getIdeas().size() + 1;
    return number;
}

int table_veiw::columnCount(const QModelIndex & parent) const
{
    return 4;
}

QVariant table_veiw::data(const QModelIndex & index, int role) const
{
    int row = index.row();
    int column = index.column();

    std::vector<idea> ideas = this->_ctrl->getIdeas();

    if (row == ideas.size())
    {
        return QVariant();
    }

    idea c = ideas[row];

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        switch (column)
        {
        case 0:
            return QString::fromStdString(c.getDesc());
        case 1:
            return QString::fromStdString(c.getStatus());
        case 2:
            return QString::fromStdString(c.getCreator());
        case 3:
            return QString::fromStdString(std::to_string(c.getAct()));
        default:
            break;
        }
    }

    return QVariant{};
}

QVariant table_veiw::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString{ "Description" };
            case 1:
                return QString{ "Status" };
            case 2:
                return QString{ "Creator" };
            case 3:
                return QString{ "Act" };
            default:
                break;
            }
        }
    }
    if (role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

bool table_veiw::setData(const QModelIndex & index, const QVariant & value, int role)
{
    if (!index.isValid() || role != Qt::EditRole)
        return false;

    int ideaIndex = index.row();

    std::vector<idea> ideas = this->_ctrl->getIdeas();

    if (ideaIndex == ideas.size())
    {
        this->beginInsertRows(QModelIndex{}, ideaIndex, ideaIndex);
        QString quotes = "";
        switch (index.column())
        {
        case 0:
            this->_ctrl->addIdea(idea{value.toString().toStdString(), quotes.toStdString(), quotes.toStdString(), quotes.toInt() });
            break;
        case 1:
            this->_ctrl->addIdea(idea( quotes.toStdString(), value.toString().toStdString(), quotes.toStdString(),quotes.toInt()));
            break;
        case 2:
            this->_ctrl->addIdea(idea{ quotes.toStdString(), quotes.toStdString(), value.toString().toStdString(), quotes.toInt()});
            break;
        case 3:
            this->_ctrl->addIdea(idea{ quotes.toStdString(), quotes.toStdString(), quotes.toStdString(), value.toInt()});
            break;
        }

        this->endInsertRows();
        return true;
    }

    idea& currentidea = ideas[ideaIndex];
    switch (index.column())
    {
    case 0:
        currentidea.setDesc(value.toString().toStdString());
        break;
    case 1:
        currentidea.setStatus(value.toString().toStdString());
        break;
    case 2:
        currentidea.setCreator(value.toString().toStdString());
        break;
    case 3:
        currentidea.setAct(value.toInt());
    }

    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags table_veiw::flags(const QModelIndex & index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}


