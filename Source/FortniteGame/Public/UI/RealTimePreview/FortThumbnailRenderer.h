// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortThumbnailRenderer.generated.h"

class AActor;
class UMaterialInterface;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;
class UWorld;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortThumbnailRenderer : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CaptureAlphaMask();

	UFUNCTION(BlueprintCallable)
	void CaptureDiffuse();

	UFUNCTION(BlueprintCallable)
	void CaptureEffects();

	UFUNCTION(BlueprintCallable)
	UTextureRenderTarget2D* GetOrCreateAlphaMaskRenderTarget();

	UFUNCTION(BlueprintCallable)
	UTextureRenderTarget2D* GetOrCreateDiffuseRenderTarget();

	UFUNCTION(BlueprintCallable)
	UTextureRenderTarget2D* GetOrCreateEffectsRenderTarget();

	UFUNCTION(BlueprintPure)
	int32 GetRendererIndex() const;

	UFUNCTION(BlueprintCallable)
	virtual void ReclaimResources();

	UFUNCTION(BlueprintCallable)
	virtual void ReleaseResources();

	UFUNCTION(BlueprintCallable)
	void SetAlphaMaskedActors(const TArray<AActor*>& InCaptureTarget);

	UFUNCTION(BlueprintCallable)
	void SetCaptureTarget(AActor* InCaptureTarget);

	UFUNCTION(BlueprintCallable)
	void SetRenderTargetSize(int32 Width, int32 Height);

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortThumbnailRenderer")
	TObjectPtr<UMaterialInterface> AlphaMaskMaterial;

	UPROPERTY(EditDefaultsOnly, Category="FortThumbnailRenderer")
	TObjectPtr<UMaterialInterface> EffectMaskMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UWorld> PrivateWorld;

	UPROPERTY(Transient)
	int32 RendererIndex;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	int32 SurfaceWidth;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	int32 SurfaceHeight;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	TObjectPtr<UTextureRenderTarget2D> DiffuseRT;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	TObjectPtr<UTextureRenderTarget2D> AlphaMaskRT;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	TObjectPtr<UTextureRenderTarget2D> EffectsRT;

	UPROPERTY(VisibleAnywhere, Export, Category="FortThumbnailRenderer", meta=(EditInline="true"))
	TObjectPtr<USceneCaptureComponent2D> CaptureComponent;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	TWeakObjectPtr<AActor> CaptureTargetPtr;

	UPROPERTY(VisibleAnywhere, Category="FortThumbnailRenderer")
	TArray<TWeakObjectPtr<AActor>> AlphaMaskActorPtrs;

};

