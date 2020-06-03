object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 513
  ClientWidth = 878
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 82
    Top = 31
    Width = 74
    Height = 13
    Caption = 'Info from array'
  end
  object Label2: TLabel
    Left = 108
    Top = 303
    Width = 48
    Height = 13
    Caption = 'New node'
  end
  object Label4: TLabel
    Left = 16
    Top = 403
    Width = 140
    Height = 13
    Caption = 'Write key to search or delete'
  end
  object LabelFIO: TLabel
    Left = 88
    Top = 477
    Width = 4
    Height = 13
    Caption = '-'
  end
  object Label5: TLabel
    Left = 16
    Top = 477
    Width = 66
    Height = 13
    Caption = 'Searched info'
  end
  object Label6: TLabel
    Left = 670
    Top = 50
    Width = 68
    Height = 13
    Caption = 'Info from tree'
  end
  object Label7: TLabel
    Left = 43
    Top = 50
    Width = 23
    Height = 13
    Caption = 'Keys'
  end
  object Label8: TLabel
    Left = 128
    Top = 50
    Width = 56
    Height = 13
    Caption = 'Information'
  end
  object Label9: TLabel
    Left = 585
    Top = 321
    Width = 32
    Height = 13
    Caption = 'Order:'
  end
  object Label3: TLabel
    Left = 670
    Top = 371
    Width = 94
    Height = 13
    Caption = 'Middle value search'
  end
  object Label10: TLabel
    Left = 670
    Top = 421
    Width = 36
    Height = 13
    Caption = 'Answer'
  end
  object Label11: TLabel
    Left = 738
    Top = 421
    Width = 4
    Height = 13
    Caption = '-'
  end
  object Label12: TLabel
    Left = 639
    Top = 440
    Width = 67
    Height = 13
    Caption = 'Nearest value'
  end
  object Label13: TLabel
    Left = 738
    Top = 440
    Width = 4
    Height = 13
    Caption = '-'
  end
  object MemoKey: TMemo
    Left = 24
    Top = 69
    Width = 65
    Height = 197
    TabOrder = 0
  end
  object Button7: TButton
    Left = 87
    Top = 272
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 1
    OnClick = Button7Click
  end
  object MemoFIO: TMemo
    Left = 102
    Top = 69
    Width = 130
    Height = 197
    TabOrder = 2
  end
  object EditNewNodeKey: TEdit
    Left = 24
    Top = 318
    Width = 65
    Height = 21
    TabOrder = 3
  end
  object EditNewNodeFIO: TEdit
    Left = 95
    Top = 318
    Width = 137
    Height = 21
    TabOrder = 4
  end
  object Button1: TButton
    Left = 88
    Top = 345
    Width = 75
    Height = 25
    Caption = 'Add'
    TabOrder = 5
    OnClick = Button1Click
  end
  object EditKey: TEdit
    Left = 162
    Top = 400
    Width = 70
    Height = 21
    TabOrder = 6
  end
  object Button6: TButton
    Left = 43
    Top = 437
    Width = 75
    Height = 25
    Caption = 'Find'
    TabOrder = 7
    OnClick = Button6Click
  end
  object Button3: TButton
    Left = 144
    Top = 437
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 8
    OnClick = Button3Click
  end
  object Button2: TButton
    Left = 296
    Top = 468
    Width = 99
    Height = 33
    Caption = 'Balance'
    TabOrder = 9
    OnClick = Button2Click
  end
  object Button5: TButton
    Left = 408
    Top = 468
    Width = 99
    Height = 33
    Caption = 'Exit'
    TabOrder = 10
    OnClick = Button5Click
  end
  object TreeView: TTreeView
    Left = 256
    Top = 37
    Width = 289
    Height = 425
    Indent = 19
    TabOrder = 11
  end
  object ListBox: TListBox
    Left = 575
    Top = 69
    Width = 271
    Height = 228
    ItemHeight = 13
    TabOrder = 12
  end
  object Button9: TButton
    Left = 701
    Top = 312
    Width = 59
    Height = 33
    Caption = 'post'
    TabOrder = 13
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 637
    Top = 312
    Width = 58
    Height = 33
    Caption = 'pre'
    TabOrder = 14
    OnClick = Button10Click
  end
  object Button8: TButton
    Left = 766
    Top = 312
    Width = 59
    Height = 33
    Caption = 'in'
    TabOrder = 15
    OnClick = Button8Click
  end
  object Button4: TButton
    Left = 685
    Top = 390
    Width = 75
    Height = 25
    Caption = 'Search'
    TabOrder = 16
    OnClick = Button4Click
  end
end
