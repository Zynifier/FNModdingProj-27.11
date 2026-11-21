// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Replay/FortReplaySpectatorPawnBase.h"
#include "FortReplayMovableSpotLight.generated.h"

class USpotLightComponent;

UCLASS(MinimalAPI, HideCategories=("Navigation"))
class AFortReplayMovableSpotLight : public AFortReplaySpectatorPawnBase
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_RepColor();

	UFUNCTION()
	void OnRep_RepEnabled();

	UFUNCTION()
	void OnRep_RepInnerAngle();

	UFUNCTION()
	void OnRep_RepIntensity();

	UFUNCTION()
	void OnRep_RepOuterAngle();

	UFUNCTION()
	void OnRep_RepRadius();

	UFUNCTION()
	void OnRep_RepTemperature();

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USpotLightComponent> SpotLightComp;

	UPROPERTY(Replicated)
	bool bGroupMoveLocked;

	UPROPERTY(Replicated)
	int32 LightIndex;

	UPROPERTY(ReplicatedUsing=OnRep_RepInnerAngle)
	float RepInnerAngle;

	UPROPERTY(ReplicatedUsing=OnRep_RepOuterAngle)
	float RepOuterAngle;

	UPROPERTY(ReplicatedUsing=OnRep_RepIntensity)
	float RepIntensity;

	UPROPERTY(ReplicatedUsing=OnRep_RepRadius)
	float RepRadius;

	UPROPERTY(ReplicatedUsing=OnRep_RepColor)
	uint8 RepColorR;

	UPROPERTY(ReplicatedUsing=OnRep_RepColor)
	uint8 RepColorG;

	UPROPERTY(ReplicatedUsing=OnRep_RepColor)
	uint8 RepColorB;

	UPROPERTY(ReplicatedUsing=OnRep_RepTemperature)
	float RepTemperature;

	UPROPERTY(ReplicatedUsing=OnRep_RepEnabled)
	bool bRepEnabled;

	UPROPERTY(Transient, Replicated)
	bool bDebugDraw;

};

