// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "AthenaMapChallengeListEntry.generated.h"

class UAthenaChallengeListEntry_Challenge;
class UAthenaMapNavigableIconSingleChallenge;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapChallengeListEntry : public UCommonUserWidget, public IUserListEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaMapNavigableIconSingleChallenge> IconWidget;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaChallengeListEntry_Challenge> ChallengeListEntry;

};

