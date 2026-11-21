// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "TimeOfDay/FortDayPhase.h"
#include "FortTimeOfDayEditorViewSettings.generated.h"

class UFortTimeOfDayWeatherComponent;

USTRUCT()
struct FTimeOfDayEditorViewSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorSettings", meta=(EditCondition="!bUseSpecificTimeOfDayEditing"))
	EFortDayPhase CurrentTimeOfDayEditing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleAnywhere, Category="TimeOfDayEditorSettings")
	float CurrentTimeOfDayEditingInHours;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorSettings", meta=(DisplayName="Use Specific Time Of Day In Editor"))
	bool bUseSpecificTimeOfDayEditing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorSettings", meta=(DisplayName="Specific Time Of Day In Editor", EditCondition="bUseSpecificTimeOfDayEditing"))
	FString SpecificTimeOfDayEditingString;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorSettings", meta=(ClampMax="24", ClampMin="0", DisplayName="Specific Time Of Day In Editor Scrubber", EditCondition="bUseSpecificTimeOfDayEditing", UIMax="24", UIMin="0"))
	float SpecificTimeOfDayEditing;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorSettings", meta=(DisplayName="PIE With Time Frozen"))
	bool bPIEWithTimeFrozen;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	bool bUseOverrideLightAngle;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorSettings", meta=(editcondition="bUseOverrideLightAngle"))
	FRotator OverrideLightAngle;
#endif

};

USTRUCT()
struct FTimeOfDayEditorWeatherSettings
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorWeatherSettings")
	TSoftClassPtr<UFortTimeOfDayWeatherComponent> WeatherComponentOverride;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorWeatherSettings", meta=(ClampMin="-1.000000", UIMin="-1.000000"))
	int32 WeatherEventIndex;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="TimeOfDayEditorWeatherSettings", meta=(ClampMax="1.000000", ClampMin="0.000000", UIMax="1.000000", UIMin="0.000000"))
	float WeatherEventBlendPercentage;
#endif

};

