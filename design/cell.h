#pragma once

#include "common.h"
#include "formula.h"

class Cell : public CellInterface {
public:
    Cell();
    ~Cell();

    void Set(std::string text);
    void Clear();

    Value GetValue() const override;
    std::string GetText() const override;

private:
//Новое
хранилище ячеек на которые ссылается ячейка для проверки цикла
    unordered_set<Cell*> cycle_check;
контейнер при измененеие ячейки ячейки по которым нужно пройти чтобы инвалидировать кэш;
    unordered_set<Cell*> cash_cell;
если ячейка формульная то есть поле дополнительное 
double cash;
Если значение меняется следущий метод вызывается 
    void GetCellTable(Sheet& sheet, unordered_set<Cell*> cash_cell);
в нем меняется значение ячейке и кэша которые берут значение из этой ячейки

    class Impl;
    class EmptyImpl;
    class TextImpl;
    class FormulaImpl;
    std::unique_ptr<Impl> impl_;
};
