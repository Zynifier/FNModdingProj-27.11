// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortPlayerCharm.generated.h"

class ACustomCosmeticCharmModifier;
class UAthenaCharmItemDefinition;
class USceneComponent;
class USkeletalMeshComponentBudgeted;
class USoundBase;

UCLASS(Abstract, BlueprintType, Blueprintable)
class AFortPlayerCharm : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortPlayerCharm")
	USceneComponent* GetCharmAttachedToComponent() const;

	UFUNCTION(BlueprintPure, Category="FortPlayerCharm")
	FName GetCharmAttachedToSocket() const;

	UFUNCTION(BlueprintPure, Category="FortPlayerCharm")
	USkeletalMeshComponentBudgeted* GetCharmMeshComponent() const;

	UFUNCTION(BlueprintPure, Category="FortPlayerCharm")
	USoundBase* GetCharmSoundAssetByDescName(const FName DescNameIn, bool& bValidOut) const;

	UFUNCTION(BlueprintPure, Category="FortPlayerCharm")
	USoundBase* GetCharmSoundAssetByIndex(const int32 IndexIn, bool& bValidOut) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic)
	void PreDestruction();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCharmVisibilityChanged(bool bVisible);

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerCharm")
	TObjectPtr<UAthenaCharmItemDefinition> CharmItemDef;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerCharm", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> CharmMesh;

	UPROPERTY()
	bool bIsFrontEndPreview;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> CharmAttachedTo;

	UPROPERTY(Transient)
	FName CharmAttachedToSocket;

	UPROPERTY(Transient)
	TObjectPtr<ACustomCosmeticCharmModifier> CharmModifier;

};

