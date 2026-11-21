// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaQuestListContent.generated.h"

class IAthenaChallengeListEntryContextInterface;
class UAthenaChallengeNpcQuestListView;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaQuestListContent : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaQuestListContent", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaChallengeNpcQuestListView> ListView_Quests;

	UPROPERTY(EditAnywhere, Category="AthenaQuestListContent")
	FDataTableRowHandle PlaceMarkerBinding;

	UPROPERTY(EditAnywhere, Category="AthenaQuestListContent")
	FDataTableRowHandle RemoveMarkerBinding;

	UPROPERTY(Transient)
	TScriptInterface<IAthenaChallengeListEntryContextInterface> QuestEntriesContext;

};

