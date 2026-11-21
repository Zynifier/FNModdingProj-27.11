// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "FortAthenaPatrolPoint.generated.h"

class AFortAthenaLocalGameplayBehavior;
class UBillboardComponent;
class UPatrolPointRenderingComponent;

UCLASS(MinimalAPI)
class AFortAthenaPatrolPoint : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="LocalGameplayBehavior")
	TObjectPtr<AFortAthenaLocalGameplayBehavior> LocalGameplayBehavior;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UBillboardComponent> SpriteComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPatrolPointRenderingComponent> RenderingComponent;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TSoftObjectPtr<AFortAthenaLocalGameplayBehavior> LocalGameplayBehaviorSoftCopy;
#endif

};

UCLASS(HideCategories=("Object", "Mobility", "VirtualTexture", "Trigger"))
class UPatrolPointRenderingComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

};

