// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ContentWidget.h"
#include "Engine/EngineTypes.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "KairosViewport.generated.h"

class AActor;
class AGameModeBase;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;

UCLASS()
class UKairosViewport : public UContentWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Appearance")
	FLinearColor BackgroundColor;

private:
	UPROPERTY(EditAnywhere, Category="Effect")
	TObjectPtr<UMaterialInterface> EffectMaterial;

	UPROPERTY(EditAnywhere, Category="Camera")
	TEnumAsByte<ESceneCaptureSource> CaptureSource;

	UPROPERTY(EditAnywhere, Category="Camera")
	FVector ViewLocation;

	UPROPERTY(EditAnywhere, Category="Camera")
	FRotator ViewRotation;

	UPROPERTY(EditAnywhere, Category="World")
	TSubclassOf<AGameModeBase> DefaultGameMode;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> DynamicMaterial;

	UPROPERTY(VisibleInstanceOnly, Transient, Category="Runtime Debugging")
	TObjectPtr<UTextureRenderTarget2D> RenderTarget;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneCaptureComponent2D> CaptureComponent;

	UPROPERTY(EditAnywhere, Category="KairosViewport")
	TSubclassOf<AActor> ViewportActorClass;

	UPROPERTY(Transient)
	TArray<TObjectPtr<AActor>> SpawnedActors;

};

