// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerInfoBaseWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "SpecialEventPlayerInfoWidget.generated.h"

class AFortPlayerStateAthena;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSpecialEventPlayerInfoWidgetRepresentedPlayerStateChanged, AFortPlayerStateAthena*, OldPlayerState, AFortPlayerStateAthena*, NewPlayerState);

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class USpecialEventPlayerInfoWidget : public UFortHUDElementWidget, public IAthenaPlayerInfoBaseWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AFortPlayerStateAthena* GetRepresentedPlayerState() const;

	UPROPERTY(BlueprintAssignable)
	FSpecialEventPlayerInfoWidgetRepresentedPlayerStateChanged OnRepresentedPlayerStateChanged;

};

