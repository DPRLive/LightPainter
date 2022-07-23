// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "PainterSaveGame.h"

// TSubclassOf<AŬ����>��, Ŭ������ �������� �������ش�.
// ex) TSubclassOf<SaveGame>�� SaveGame���� �Ļ��� Ŭ������ ���ð�����.
UPainterSaveGame* UPainterSaveGame::Create()
{
	// StaticClass�� ������ Ÿ�ӿ� Ŭ������ ���� ������ ������
	USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(StaticClass());
	return Cast<UPainterSaveGame>(NewSaveGame);
}

bool UPainterSaveGame::Save()
{
	return UGameplayStatics::SaveGameToSlot(this, TEXT("Test"), 0);
}
