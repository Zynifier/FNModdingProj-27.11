// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Math/MathFwd.h"
#include "FabricScreenComponent.generated.h"

class AFMInWorldKnobActorBase;
class UFMInWorldKnobActorCopyComponent;
class UFabricScreenLayoutDataAsset;
class UFabricScreenWidget;
class UFabricWidget;
class UStaticMesh;
class UWidgetComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWidgetAdded, UFabricWidget*, FabricWidget);

USTRUCT(BlueprintType)
struct FScreenMeshArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ScreenMeshArray")
	TArray<TSoftObjectPtr<UStaticMesh>> ScreenMeshArrayByHeight;

};

USTRUCT()
struct FScreenWidgetLayoutInfo
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMINWORLDKNOBSRUNTIME_API UFabricScreenComponent : public USceneComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FVector ConvertGridPositionToUnrealLocation(FVector2D GridPosition) const;

	UFUNCTION(BlueprintPure)
	FVector2D ConvertUnrealLocationToGridPosition(FVector UnrealPosition) const;

	UFUNCTION(BlueprintPure)
	int32 GetScreenGridHeight() const;

	UFUNCTION(BlueprintPure)
	int32 GetScreenGridWidth() const;

	UFUNCTION(BlueprintCallable)
	void Initialize(UWidgetComponent* InScreenWidgetComponent, int32 InWidth, int32 InHeight, UFabricScreenLayoutDataAsset* ScreenLayout);

	UFUNCTION(BlueprintCallable)
	void SetScreenSize(int32 InWidth, int32 InHeight);

	UFUNCTION(BlueprintPure)
	FVector SnapUnrealLocationToScreenGrid(FVector UnrealPosition) const;

	UPROPERTY(BlueprintAssignable)
	FOnWidgetAdded OnWidgetAdded;

private:
	UFUNCTION()
	void OnCopiedKnobActorSet(UFMInWorldKnobActorCopyComponent* CopyComponent, AFMInWorldKnobActorBase* NewKnobActor);

	UPROPERTY(VisibleAnywhere, Export, Category="FabricScreenComponent")
	TWeakObjectPtr<UFabricScreenWidget> ScreenWidget;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="FabricScreenComponent", meta=(EditInline="true"))
	TObjectPtr<UWidgetComponent> ScreenWidgetComponent;

	UPROPERTY(Transient)
	TMap<TObjectPtr<UFMInWorldKnobActorCopyComponent>, FScreenWidgetLayoutInfo> CopyComponentsToWidget;

};

