// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElectraDataChannelRecorder.generated.h"

class UMediaPlayer;

UCLASS()
class ELECTRADATACHANNELRUNTIME_API AElectraDataChannelRecorder : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void EndRecording();

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void RecordToFile(const FString& InFilename);

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void StartRecording();

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void UseTimeFromMediaPlayer(UMediaPlayer* InMediaPlayer);

};

