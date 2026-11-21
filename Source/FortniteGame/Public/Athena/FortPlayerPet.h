// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FortInteractInterface.h"
#include "FortPlayerPet.generated.h"

class AFortPlayerPawn;
class UAthenaPetItemDefinition;
class UAudioComponent;
class UFortTaggedSoundBank;
class UMaterialInterface;
class USkeletalMeshComponentBudgeted;
class USphereComponent;

UCLASS(Abstract, BlueprintType, Blueprintable)
class AFortPlayerPet : public AActor, public IFortInteractInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetFortPlayerPawn() const;

	UFUNCTION(BlueprintCallable)
	void InitalizeFromItemDef(const UAthenaPetItemDefinition* InPetItemDef);

	UFUNCTION(BlueprintCallable)
	void ReInitPetDisplay();

	UFUNCTION(BlueprintCallable)
	void ResetPetMaterials();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void PetMaterialsOverride();

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPet")
	TObjectPtr<UAthenaPetItemDefinition> PetItemDef;

	UPROPERTY(BlueprintReadOnly, Export, Category="Sounds", meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> PetAudioComponent;

	UPROPERTY(BlueprintReadOnly, Category="FortPlayerPet")
	uint8 bIsFrontEndPreview : 1;

private:
	UFUNCTION()
	void OnRequestedCustomizationComplete(AFortPlayerPawn* Pawn);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerPet", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> PetMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPlayerPet", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USphereComponent> InteractionCollisionSphere;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortPlayerPet", meta=(AllowPrivateAccess="true"))
	uint8 bSuppressInteract : 1;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UMaterialInterface>> SavedMaterials;

	UPROPERTY(Transient)
	TObjectPtr<UFortTaggedSoundBank> SoundBank;

};

