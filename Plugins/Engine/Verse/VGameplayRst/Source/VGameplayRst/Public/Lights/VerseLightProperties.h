// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "VerseLightProperties.generated.h"

class ULightComponentBase;

UCLASS()
class UVerseLightPropertiesBase : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_Intensity();

	UFUNCTION()
	void OnRep_LightColor();

	UFUNCTION()
	void OnRep_LightComponent();

	// Properties on ULightComponent (not ULightComponentBase)

	UPROPERTY(ReplicatedUsing=OnRep_Intensity)
	float Intensity;

	UPROPERTY(ReplicatedUsing=OnRep_LightColor)
	FLinearColor LightColor;

	UPROPERTY(ReplicatedUsing=OnRep_LightComponent, Export, meta=(EditInline="true"))
	TObjectPtr<ULightComponentBase> LightComponent;

};

UCLASS()
class UVerseLocalLightProperties : public UVerseLightPropertiesBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_AttenuationRadius();

	UPROPERTY(ReplicatedUsing=OnRep_AttenuationRadius)
	float AttenuationRadius;

};

UCLASS()
class UVersePointLightProperties : public UVerseLocalLightProperties
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_SourceLength();

	UFUNCTION()
	void OnRep_SourceRadius();

	UPROPERTY(ReplicatedUsing=OnRep_SourceRadius)
	float SourceRadius;

	UPROPERTY(ReplicatedUsing=OnRep_SourceLength)
	float SourceLength;

};

UCLASS()
class UVerseSpotLightProperties : public UVersePointLightProperties
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnRep_InnerConeAngle();

	UFUNCTION()
	void OnRep_OuterConeAngle();

	UPROPERTY(ReplicatedUsing=OnRep_InnerConeAngle)
	float InnerConeAngle;

	UPROPERTY(ReplicatedUsing=OnRep_OuterConeAngle)
	float OuterConeAngle;

};

