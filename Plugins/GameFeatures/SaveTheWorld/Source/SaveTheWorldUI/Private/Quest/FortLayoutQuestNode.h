// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Quests/FortQuestMapPage.h"
#include "FortLayoutQuestNode.generated.h"

class UFortQuestMapQuestTile;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortLayoutQuestNode : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLayoutQuestNode", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapQuestTile> QuestTile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLayoutQuestNode")
	int32 QuestNodeIndex;

private:
	UPROPERTY(Transient)
	FFortQuestMapNode QuestMapNode;

};

