// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Quests/FortQuestMapPage.h"
#include "FortLayoutQuestNode_Legacy.generated.h"

class UFortQuestMapQuestTile_Legacy;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortLayoutQuestNode_Legacy : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLayoutQuestNode_Legacy", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortQuestMapQuestTile_Legacy> QuestTile;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortLayoutQuestNode_Legacy")
	int32 QuestNodeIndex;

private:
	UPROPERTY(Transient)
	FFortQuestMapNode QuestMapNode;

};

