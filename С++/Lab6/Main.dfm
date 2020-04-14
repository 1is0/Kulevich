object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 575
  ClientWidth = 960
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 120
  TextHeight = 16
  object TreeView1: TTreeView
    Left = 271
    Top = 8
    Width = 273
    Height = 321
    Indent = 19
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 8
    Width = 257
    Height = 321
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
  end
  object Button1: TButton
    Left = 271
    Top = 361
    Width = 105
    Height = 49
    Caption = 'Show'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 847
    Top = 518
    Width = 105
    Height = 49
    Caption = 'Delete'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 408
    Top = 361
    Width = 105
    Height = 49
    Caption = 'Fill tree'
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 560
    Top = 361
    Width = 105
    Height = 49
    Caption = 'Preorder'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 8
    Top = 407
    Width = 105
    Height = 49
    Caption = 'String amount'
    TabOrder = 6
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 363
    Width = 105
    Height = 24
    TabOrder = 7
  end
  object Memo1: TMemo
    Left = 550
    Top = 8
    Width = 259
    Height = 321
    TabOrder = 8
  end
  object Button6: TButton
    Left = 8
    Top = 478
    Width = 105
    Height = 49
    Caption = 'Task'
    TabOrder = 9
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 696
    Top = 361
    Width = 105
    Height = 49
    Caption = 'Postorder'
    TabOrder = 10
    OnClick = Button7Click
  end
  object Edit2: TEdit
    Left = 135
    Top = 363
    Width = 90
    Height = 24
    TabOrder = 11
  end
  object Button8: TButton
    Left = 135
    Top = 407
    Width = 90
    Height = 49
    Caption = 'Search'
    TabOrder = 12
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 632
    Top = 416
    Width = 105
    Height = 49
    Caption = 'Inorder'
    TabOrder = 13
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 831
    Top = 150
    Width = 105
    Height = 49
    Caption = 'Delete Nodes'
    TabOrder = 14
    OnClick = Button10Click
  end
  object Edit3: TEdit
    Left = 831
    Top = 104
    Width = 90
    Height = 24
    TabOrder = 15
  end
  object Button12: TButton
    Left = 455
    Top = 506
    Width = 89
    Height = 37
    Caption = 'Add'
    TabOrder = 16
    OnClick = Button12Click
  end
  object Edit4: TEdit
    Left = 328
    Top = 490
    Width = 121
    Height = 24
    TabOrder = 17
  end
  object Edit5: TEdit
    Left = 328
    Top = 530
    Width = 121
    Height = 24
    TabOrder = 18
  end
end
