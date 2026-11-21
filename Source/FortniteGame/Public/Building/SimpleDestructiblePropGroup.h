// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Abilities/FortAbilitySystemInterface.h"
#include "FortDamageableActorInterface.h"
#include "FortReplicationGraphInterface.h"
#include "SimpleDestructiblePropGroup.generated.h"

class UBoxComponent;
class UFortAbilitySystemComponent;
class UFortHealthSet;
class UInstancedStaticMeshComponent;

USTRUCT()
struct FSimpleDestructiblePropGroupBitArray
{
	GENERATED_BODY()

};

UCLASS(MinimalAPI, NotBlueprintable, meta=(DisplayName="Simple Destructible Prop Group"))
class ASimpleDestructiblePropGroup : public AActor, public IFortDamageableActorInterface, public IFortAbilitySystemInterface, public IFortReplicationGraphInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	int32 CalculateNumProps() const;

	UFUNCTION(BlueprintPure)
	UFortHealthSet* GetHealthAttributeSet() const;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortHealthSet> HealthAttributeSet;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAbilitySystemComponent> AbilitySystemComponent;

private:
	UFUNCTION()
	void OnRep_OrderedReplicatedInstanceData();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OrderedReplicatedInstanceData)
	TArray<FSimpleDestructiblePropGroupBitArray> OrderedReplicatedInstanceData;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UInstancedStaticMeshComponent>> OrderedInstancedStaticMeshComps;

	UPROPERTY()
	TArray<FName> OrderedInstancedStaticMeshCollisionProfiles;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="SimpleDestructiblePropGroup", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UBoxComponent> IncomingExplosionDamageVolume;

	UPROPERTY(Transient, Replicated)
	double DamageEventServerTimestamp;

	UPROPERTY(Transient, Replicated)
	uint8 bLastDamageEventFromFire : 1;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	int32 LastBuiltPropGroupVersion;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Transient, Category="Prop Group Visibility")
	bool bAllowVisibility;
#endif

};

