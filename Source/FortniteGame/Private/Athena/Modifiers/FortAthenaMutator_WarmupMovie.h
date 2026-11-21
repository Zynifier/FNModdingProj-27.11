// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_WarmupMovie.generated.h"

class AActor;
class UCommonActivatablePanelLegacy;
class UMediaPlayer;
class USoundBase;
class USoundMix;

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_WarmupMovie : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnMediaClosedOrEndReached();

	UFUNCTION(BlueprintImplementableEvent)
	void PlayMovie();

	UFUNCTION(BlueprintImplementableEvent, Category="Leto Backwards Compatibility", meta=(BlueprintProtected="TRUE"))
	void PushMovieWidget(UCommonActivatablePanelLegacy* Widget);

	UFUNCTION(BlueprintCallable)
	void ShowMovieWidget(UCommonActivatablePanelLegacy* InMovieWidget, UMediaPlayer* InMediaPlayer);

private:
	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_WarmupMovie")
	float MovieLengthSeconds;

	UPROPERTY(Replicated)
	bool bServerMovieStart;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatablePanelLegacy> MovieWidget;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_WarmupMovie")
	TObjectPtr<USoundBase> SkydiveTransitionMusic;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_WarmupMovie")
	TObjectPtr<USoundMix> WarmupMovieMix;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCommonActivatablePanelLegacy> WaitingScreen;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_WarmupMovie")
	TSubclassOf<AActor> SpawnEffectClass;

	UPROPERTY(Transient)
	TObjectPtr<UMediaPlayer> MediaPlayer;

};

UCLASS()
class UWarmupMovieComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable)
	void ServerFinishedWatchingMovie();

};

