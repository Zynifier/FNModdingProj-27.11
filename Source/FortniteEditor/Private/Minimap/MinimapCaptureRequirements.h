// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortReleaseVersion.h"
#include "MinimapCaptureRequirements.generated.h"

class UFortPlaylistAthena;
class UMinimapCaptureRequirements;

USTRUCT(BlueprintType)
struct FMinimapCaptureRequest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MinimapCaptureRequest")
	TSoftObjectPtr<UFortPlaylistAthena> Playlist;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MinimapCaptureRequest")
	TArray<FString> CalendarEvents;

};

UCLASS()
class UMinimapCaptureRequirementStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Capture")
	static UMinimapCaptureRequirements* FindCurrentCaptureRequirements();

};

UCLASS(BlueprintType)
class UMinimapCaptureRequirements : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetupCaptureRequest(FMinimapCaptureRequest Request);

	UPROPERTY(EditAnywhere, Category="Version")
	FFortReleaseVersion Version;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Requirements")
	FMinimapCaptureRequest DefaultCapture;

};

