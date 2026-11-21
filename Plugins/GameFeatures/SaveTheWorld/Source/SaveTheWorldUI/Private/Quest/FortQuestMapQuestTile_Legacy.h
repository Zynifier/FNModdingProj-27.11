// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Quests/FortQuestMapPage.h"
#include "FortQuestMapQuestTile_Legacy.generated.h"

class UCommonButtonLegacy;
class UFortQuestItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapQuestTile_Legacy : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Quest Map Quest Tile")
	void GetQuestNodeData(UFortQuestItemDefinition*& QuestItemDefinition, FFortQuestMapNode& NodeData) const;

	UFUNCTION(BlueprintImplementableEvent, Category="Quest Map Quest Tile", meta=(DisplayName="Handle Quest Data Changed"))
	void HandleQuestDataChangedBP();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleSelectedChange(bool Selected);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortQuestMapQuestTile_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> QuestButton;

private:
	UPROPERTY(Transient)
	FFortQuestMapNode QuestNodeData;

};

