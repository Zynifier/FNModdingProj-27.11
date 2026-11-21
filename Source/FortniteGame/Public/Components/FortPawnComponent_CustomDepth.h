// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnComponent.h"
#include "FortPawnComponent_CustomDepth.generated.h"

class UPrimitiveComponent;

UENUM()
enum class EUpdateCustomDepthOptimDirtyFlags : uint8
{
	None = 0,
	CharacterParts = 1,
	Weapon = 2,
	PossessedProp = 4,
};

USTRUCT(BlueprintType)
struct FCustomHighlighting
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CustomHighlighting")
	bool bShouldHighlight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CustomHighlighting")
	uint8 FriendlyStencilValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CustomHighlighting")
	uint8 EnemyStencilValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="CustomHighlighting")
	uint8 TeamDisplayOverride;

};

USTRUCT(BlueprintType)
struct FCustomHighlightingHandle
{
	GENERATED_BODY()

};

USTRUCT()
struct FCustomHighlightingOverrideData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FCustomHighlighting CustomHighlightingOverride;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortPawnComponent_CustomDepth : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Rendering")
	static void ForceRenderCustomDepthUpdateForAllActors();

	UFUNCTION(BlueprintPure, Category="CustomDepth")
	bool IsRenderCustomDepthEnabled() const;

	UFUNCTION(BlueprintCallable, Category="CustomDepth")
	void Update(float DeltaTime, bool bForcedUpdate = false);

protected:
	UFUNCTION()
	void OnRep_EnableRenderCustomDepth();

	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_EnableRenderCustomDepth, Category="PawnSettings", meta=(AllowPrivateAccess="true"))
	uint8 bEnableRenderCustomDepth : 1;

	UPROPERTY(Transient)
	TArray<FCustomHighlightingOverrideData> CustomHighlightingDataPriorityStack;

	UPROPERTY(EditDefaultsOnly, Category="FortPawnComponent_CustomDepth")
	FCustomHighlighting DefaultHighlightingData;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UPrimitiveComponent>> CustomDepthMatchedComponents;

};

