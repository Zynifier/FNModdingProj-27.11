// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortTeamMemberEntryBase.h"
#include "FortLobbyAddPlayer.generated.h"

class UCommonButtonLegacy;
class UFortPartySuggestionButton;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortLobbyAddPlayer : public UFortTeamMemberEntryBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EmptySlot;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortLobbyAddPlayer", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortPartySuggestionButton> PartySuggestion;

};

