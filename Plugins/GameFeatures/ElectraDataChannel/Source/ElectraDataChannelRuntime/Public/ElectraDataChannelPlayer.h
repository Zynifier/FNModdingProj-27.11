// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElectraDataChannelPlayer.generated.h"

class UMediaPlayer;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTerminalDataChannelError, FString, FailureReason);

UCLASS()
class ELECTRADATACHANNELRUNTIME_API AElectraDataChannelPlayer : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void EndPlayback();

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void PlayFromFile(const FString& InFilename);

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void PlayFromMediaPlayer(UMediaPlayer* InMediaPlayer);

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void PlayFromStateStreamServer(const FString& InStatePlaylistURL);

	UFUNCTION(BlueprintCallable, Category="DataChannel")
	void UseTimeFromMediaPlayer(UMediaPlayer* InMediaPlayer);

	UPROPERTY(BlueprintAssignable, Category="DataChannel")
	FOnTerminalDataChannelError OnTerminalError;

};

