// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortFXCustomizationComponent.generated.h"

class AActor;
class UFXSystemAsset;
class UFXSystemComponent;
class UFortFXCustomizationComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnFXCustomizationAppliedDelegate, UFortFXCustomizationComponent*, FXCustomizationComp, UFXSystemComponent*, TargetFXComp, UFXSystemAsset*, TargetFXAsset);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortFXCustomizationComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UFortFXCustomizationComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Apply FX Customization to Actor", ReturnDisplayName="Customization Applied"))
	static bool ApplyFXCustomizationToActor(const AActor* SourceActor, const AActor* TargetActor, const bool bApplyToChildActors = false);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="Apply FX Customization to Component", ReturnDisplayName="Customization Applied"))
	static bool ApplyFXCustomizationToComponent(const AActor* SourceActor, UFXSystemComponent* TargetFXComp);

	UPROPERTY(BlueprintAssignable)
	FOnFXCustomizationAppliedDelegate OnFXCustomizationApplied;

protected:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Apply FX Customization", ReturnDisplayName="Customization Applied"))
	bool ApplyFXCustomizationInternal(UFXSystemComponent* TargetFXComp);

	UPROPERTY(EditDefaultsOnly, Category="FortFXCustomizationComponent")
	TArray<FParticleParamterVariant> ParticleParams;

};

