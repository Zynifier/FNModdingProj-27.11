// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "AssembledMeshUserComponent.generated.h"

class UAssembledMeshSchema;
class UCustomizableSkeletalComponent;
class USkeletalMeshComponent;

USTRUCT()
struct FAssembledComponentReferences
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCustomizableSkeletalComponent> CustomizableComponent;

	UPROPERTY(Transient)
	FGameplayTag AssembledMeshSchemaTag;

};

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class ASSEMBLEDMESHSYSTEM_API UAssembledMeshUserComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void GatherAndAssignAssembledMeshParts();

#if WITH_EDITORONLY_DATA
	UPROPERTY(BlueprintGetter=GetMeshPart, BlueprintSetter=SetMeshPart, Category="AssembledMeshUserComponent")
	TObjectPtr<UAssembledMeshSchema> MeshPart;
#endif

protected:
	UFUNCTION(BlueprintNativeEvent)
	USkeletalMeshComponent* GetAttachToComponent();

	UPROPERTY(EditDefaultsOnly, Category="Assembled Parts")
	bool bAssignMeshPartsOnBeginPlay;

private:
	UFUNCTION()
	void CustomizationCompleted(const int32 PartIndex);

	UFUNCTION(BlueprintPure, meta=(BlueprintInternalUseOnly="true", BlueprintType="true"))
	UAssembledMeshSchema* GetMeshPart() const;

	UFUNCTION()
	void OnRep_MeshParts();

	UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true", BlueprintType="true", Keywords="AnimBlueprint"))
	void SetMeshPart(UAssembledMeshSchema* InMeshPart);

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_MeshParts, Category="Assembled Parts")
	TArray<TObjectPtr<UAssembledMeshSchema>> MeshParts;

	UPROPERTY(Transient)
	TArray<FAssembledComponentReferences> MeshPartComponents;

};

