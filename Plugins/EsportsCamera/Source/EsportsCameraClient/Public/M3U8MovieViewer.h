// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundWaveProcedural.h"
#include "WebCamBase.h"
#include "M3U8MovieViewer.generated.h"

class UAudioComponent;
class UMySoundWave;

UENUM()
enum class EM3U8StreamState : uint8
{
	RequestingM3U8 = 0,
	M3U8Received = 1,
	M3U8Failed = 2,
	StartFirstBuffering = 3,
	FirstBufferingComplete = 4,
	PlayingTS = 5,
	TSFinished = 6,
	TSError = 7,
};

UCLASS()
class ESPORTSCAMERACLIENT_API AM3U8MovieViewer : public AWebCamBase
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> AudioComponent;

	UPROPERTY()
	TObjectPtr<UMySoundWave> MySoundWave;

};

UCLASS(HideCategories=("Object", "Object"))
class UMySoundWave : public USoundWaveProcedural
{
	GENERATED_BODY()

public:
	UMySoundWave(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

