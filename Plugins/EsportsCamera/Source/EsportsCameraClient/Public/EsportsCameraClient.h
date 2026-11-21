// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EsportsCameraClient.generated.h"

class AM3U8MovieViewer;
class AWebCamReader;
class AWebCamViewer;
class UMaterialInstanceDynamic;

UENUM()
enum class EDisplayMode : uint8
{
	None = 0,
	WebCam = 1,
	M3U8MovieTest = 2,
};

UCLASS()
class ESPORTSCAMERACLIENT_API AEsportsCameraClient : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="EsportsWebCam")
	bool HasDynamicMaterial();

	UFUNCTION(BlueprintCallable, Category="EsportsWebCam")
	bool IsPlatformEnabled();

	UFUNCTION(BlueprintCallable, Category="EsportsWebCam")
	bool IsPlayingWebMovie();

	UFUNCTION(BlueprintCallable, Category="EsportsWebCam")
	void SetDynamicMaterial(UMaterialInstanceDynamic* MaterialInstanceDynamic);

protected:
	UPROPERTY()
	TObjectPtr<AWebCamReader> WebCamReader;

	UPROPERTY()
	TObjectPtr<AWebCamViewer> WebCamViewer;

	UPROPERTY()
	TObjectPtr<AM3U8MovieViewer> M3U8MovieViewer;

};

