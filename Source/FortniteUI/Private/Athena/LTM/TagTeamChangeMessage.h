// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "TagTeamChangeMessage.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTagTeamChangeMessage : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetTeam(bool bIsIt);

	UPROPERTY(EditAnywhere, Category="TagTeamChangeMessage")
	FGameplayTag BlueTeamTag;

	UPROPERTY(EditAnywhere, Category="TagTeamChangeMessage")
	FGameplayTag RedTeamTag;

};

