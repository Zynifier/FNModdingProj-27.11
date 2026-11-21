// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RebootRallyTimerBase.generated.h"

class URebootRallyQuestDataAsset;

UCLASS(Abstract, meta=(DisableNativeTick))
class URebootRallyTimerBase : public UUserWidget
{
	GENERATED_BODY()

public:
	URebootRallyTimerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure)
	const FText& GetRemainingTimeForRebootRallyEnd() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateRemainingTime();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Quests Data")
	TSoftObjectPtr<URebootRallyQuestDataAsset> RebootRallyQuestDataPtr;

private:
	UPROPERTY(BlueprintReadOnly, Category="RebootRallyTimerBase", meta=(AllowPrivateAccess))
	FText RemainingTimeForRebootRallyEnd;

};

