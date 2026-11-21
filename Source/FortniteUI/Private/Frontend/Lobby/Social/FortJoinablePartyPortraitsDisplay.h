// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortJoinablePartyPortraitsDisplay.generated.h"

class UDynamicEntryBox;
class UFortJoinablePartyPortrait;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UFortJoinablePartyPortraitsDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortJoinablePartyPortraitsDisplay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyPortraitsDisplay", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_PartyPortraits;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyPortraitsDisplay", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortJoinablePartyPortrait> PartyPortrait_PartyLeader;

	UPROPERTY(EditInstanceOnly, Category="FortJoinablePartyPortraitsDisplay")
	int32 MaxDisplayedUsers;

};

