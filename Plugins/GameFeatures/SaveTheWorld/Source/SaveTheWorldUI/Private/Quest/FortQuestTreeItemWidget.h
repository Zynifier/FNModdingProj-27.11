// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonButtonBase.h"
#include "FortQuestTreeItemWidget.generated.h"

class UFortQuestCategory;
class UFortQuestItem;
class UObject;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortQuestTreeItemWidget : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleQuestsUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestsUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void SetupAsCategory(UFortQuestCategory* Category);

	UFUNCTION(BlueprintImplementableEvent)
	void SetupAsQuest(UFortQuestItem* Category);

	UPROPERTY(BlueprintReadOnly, Category="FortQuestTreeItemWidget")
	TWeakObjectPtr<UObject> QuestOrCategory;

};

