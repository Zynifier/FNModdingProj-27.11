// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FortItemWrapOverrideComponent.generated.h"

class AActor;
class UAthenaItemWrapDefinition;
class UFortItemWrapOverrideComponent;
class UMaterialInterface;
class UPrimitiveComponent;

USTRUCT()
struct FFortMaterialsPriorToOverride
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UMaterialInterface>> OwnedMaterials_AssumeExternalOrder;

};

UCLASS()
class UFortItemWrapOverrideComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ItemWrapOverride", meta=(AutoCreateRefTerm="VariantInfo"))
	static UFortItemWrapOverrideComponent* OverrideWrapOnActor(AActor* ActorBase, const TSoftObjectPtr<UAthenaItemWrapDefinition>& Wrap, const TArray<FMcpVariantChannelInfo>& VariantData);

	UFUNCTION(BlueprintCallable, Category="ItemWrapOverride")
	void RemoveWrapFromOwner();

protected:
	UFUNCTION()
	void OnRep_SoftOverride();

	UFUNCTION()
	void OnRep_VariantData();

	UPROPERTY(ReplicatedUsing=OnRep_SoftOverride)
	TSoftObjectPtr<UAthenaItemWrapDefinition> ReplicatedItemWrapOverride;

	UPROPERTY()
	TObjectPtr<UAthenaItemWrapDefinition> CurrentOverrideHardRef;

	UPROPERTY(ReplicatedUsing=OnRep_VariantData)
	TArray<FMcpVariantChannelInfo> VariantInfo;

	UPROPERTY()
	TMap<TObjectPtr<UPrimitiveComponent>, FFortMaterialsPriorToOverride> OriginalMaterials;

};

