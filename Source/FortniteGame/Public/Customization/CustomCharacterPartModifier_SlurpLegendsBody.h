// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "Customization/CustomCharacterPartModifier.h"
#include "CustomCharacterPartModifier_SlurpLegendsBody.generated.h"

class AFortPlayerStateZone;
class UAnimInstance;
class UMaterialInstanceDynamic;
class UNiagaraComponent;
class UParticleSystemComponent;

USTRUCT()
struct FSlurpLegendSwapToVariantData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SlurpLegendSwapToVariantData")
	float DelayBeforeSwitching;

	UPROPERTY(EditAnywhere, Category="SlurpLegendSwapToVariantData")
	FMcpVariantChannelInfo VariantData;

};

UCLASS()
class ACustomCharacterPartModifier_SlurpLegendsBody : public ACustomCharacterPartModifier
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetCurrentShieldPercentage() const;

	UFUNCTION(BlueprintCallable)
	void SetComponentPointers(UParticleSystemComponent* xFormBurst, UNiagaraComponent* DripLoop);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> TransformBurst;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> LoopingDrip;

	UPROPERTY(EditAnywhere, Category="CustomCharacterPartModifier_SlurpLegendsBody")
	float InterpolationRate;

	UPROPERTY(EditAnywhere, Category="CustomCharacterPartModifier_SlurpLegendsBody", meta=(EditCondition="bUseShieldOverride"))
	float ShieldOverride;

	UPROPERTY(EditAnywhere, Category="CustomCharacterPartModifier_SlurpLegendsBody")
	bool bUseShieldOverride;

	UPROPERTY(EditAnywhere, Category="CustomCharacterPartModifier_SlurpLegendsBody")
	TArray<FSlurpLegendSwapToVariantData> VariantData;

protected:
	UPROPERTY()
	TObjectPtr<AFortPlayerStateZone> AssociatedPS;

	UPROPERTY()
	TObjectPtr<UAnimInstance> AssociatedAnimInstance;

	UPROPERTY()
	TObjectPtr<UMaterialInstanceDynamic> BodyMID;

};

