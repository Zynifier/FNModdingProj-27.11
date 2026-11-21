// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Quests/FortQuestMapPage.h"
#include "FortQuestMapQuestTile.generated.h"

class UCommonButtonBase;
class UFortQuestItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapQuestTile : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Quest Map Quest Tile")
	void GetQuestNodeData(UFortQuestItemDefinition*& QuestItemDefinition, FFortQuestMapNode& NodeData) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Quest Map Quest Tile", meta=(DisplayName="Handle Quest Data Changed"))
	void HandleQuestDataChangedBP();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleSelectedChange(bool Selected);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapQuestTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> QuestButton;

private:
	UPROPERTY(Transient)
	FFortQuestMapNode QuestNodeData;

};

