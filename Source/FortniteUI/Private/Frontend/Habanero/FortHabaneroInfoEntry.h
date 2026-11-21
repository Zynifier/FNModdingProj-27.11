// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortHabaneroInfoEntry.generated.h"

class UFortHabaneroDisplayData;

UCLASS(meta=(DisableNativeTick))
class UFortHabaneroInfoEntry : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetGameMode(const FString& GameMode);

private:
	UPROPERTY(EditAnywhere, Category="FortHabaneroInfoEntry", meta=(AllowPrivateAccess))
	TObjectPtr<UFortHabaneroDisplayData> HabaneroDisplayData;

};

