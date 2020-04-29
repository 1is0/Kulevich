object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 599
  ClientWidth = 541
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 342
    Top = 176
    Width = 114
    Height = 13
    Caption = 'Search or delete by key'
  end
  object Label4: TLabel
    Left = 331
    Top = 198
    Width = 18
    Height = 13
    Caption = 'Key'
  end
  object Label5: TLabel
    Left = 56
    Top = 37
    Width = 134
    Height = 13
    Caption = 'Information from hash table'
  end
  object Label1: TLabel
    Left = 362
    Top = 278
    Width = 27
    Height = 13
    Caption = 'Num  '
  end
  object Label6: TLabel
    Left = 399
    Top = 278
    Width = 28
    Height = 13
    Caption = '-------'
  end
  object Label2: TLabel
    Left = 280
    Top = 75
    Width = 150
    Height = 13
    Caption = 'Enter number of keys to create'
  end
  object Label7: TLabel
    Left = 436
    Top = 320
    Width = 20
    Height = 13
    Caption = '-----'
  end
  object Label8: TLabel
    Left = 329
    Top = 320
    Width = 74
    Height = 13
    Caption = 'Averege value:'
  end
  object Label9: TLabel
    Left = 340
    Top = 352
    Width = 60
    Height = 13
    Caption = 'Nums count:'
  end
  object Label10: TLabel
    Left = 436
    Top = 352
    Width = 20
    Height = 13
    Caption = '-----'
  end
  object Memo1: TMemo
    Left = 8
    Top = 56
    Width = 241
    Height = 529
    Lines.Strings = (
      'MemoGetALL')
    TabOrder = 0
  end
  object EditKey: TEdit
    Left = 355
    Top = 195
    Width = 83
    Height = 21
    TabOrder = 1
  end
  object Button2: TButton
    Left = 303
    Top = 235
    Width = 90
    Height = 25
    Caption = 'Search'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 399
    Top = 235
    Width = 88
    Height = 25
    Caption = 'Delete'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 363
    Top = 424
    Width = 75
    Height = 25
    Caption = 'Close'
    TabOrder = 4
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 452
    Top = 72
    Width = 61
    Height = 21
    TabOrder = 5
  end
  object Button1: TButton
    Left = 355
    Top = 112
    Width = 75
    Height = 25
    Caption = 'Create'
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button5: TButton
    Left = 363
    Top = 385
    Width = 75
    Height = 25
    Caption = 'Count'
    TabOrder = 7
    OnClick = Button5Click
  end
end
