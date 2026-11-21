// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Customization/CustomCosmeticModifierBase.h"
#include "FortCustomPartTypeEnum.h"
#include "CustomCharacterPartModifier.generated.h"

class UFXSystemComponent;
class UMeshComponent;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(ChildCanTick))
class ACustomCharacterPartModifier : public ACustomCosmeticModifierBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void ApplyVariantsToTrackedComponents();

	UFUNCTION(BlueprintCallable, Category="Custom Character")
	void ForceResetParticleSystems();

	UFUNCTION(BlueprintPure, Category="Custom Character")
	virtual const EFortCustomPartType::Type GetCharacterPartType() const;

	UFUNCTION(BlueprintPure)
	FName GetIdleFXSocketName() const;

	UFUNCTION(BlueprintPure)
	UFXSystemComponent* GetIdleVFXComponent() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	UMeshComponent* GetSkeletalMeshForAssociatedPlayerPawnPartType() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, meta=(CallInEditor="true"))
	void OnPawnAndPartChanged();

	UFUNCTION(BlueprintCallable, Category="Custom Character")
	void SetCharacterActiveVariant(const FGameplayTag& ChannelTag, const FGameplayTag& VariantTag);

	UFUNCTION(BlueprintCallable, Category="Custom Character")
	void SetChildMeshComponentsHidden(bool bHideChildComponents);

	UFUNCTION(BlueprintCallable, Category="Custom Character")
	void SetChildParticleComponentsVisible(bool bVisible);

	UFUNCTION(BlueprintPure)
	bool UsesIdleVFXNativeCustomAttachment() const;

	UPROPERTY(BlueprintReadWrite, Category="CustomCharacterPartModifier")
	FName ChildComponentTag;

	UPROPERTY(EditAnywhere, Category="VariantsSetup")
	bool bAutoApplyVariants;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> IdleVFX;

private:
	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomPartType::Type> PartType;

};

