// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortTimeOfDayManager.h"
#include "FortDayPhaseInfoOverride.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortDayPhaseInfoOverride : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DayPhase")
	FDayPhaseInfo DayPhaseInfo;

	UPROPERTY(EditDefaultsOnly, Category="HeightFogAltitudeSettings")
	bool bUseAltitudeAdjustmentsOverride;

	UPROPERTY(EditDefaultsOnly, Category="HeightFogAltitudeSettings", meta=(EditCondition="bUseAltitudeAdjustmentsOverride"))
	TArray<FCameraAltitudeAdjustments> AltitudeAdjustments;

	UPROPERTY(EditDefaultsOnly, Category="HeightFogAltitudeSettings")
	bool bUseAltitudeAdjustmentsForSecondFogOverride;

	UPROPERTY(EditDefaultsOnly, Category="HeightFogAltitudeSettings", meta=(EditCondition="bUseAltitudeAdjustmentsOverride"))
	TArray<FCameraAltitudeAdjustments> AltitudeAdjustmentsForSecondFog;

};

