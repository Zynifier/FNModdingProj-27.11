// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "Math/Color.h"
#include "FortSpectatorPlayerHighlighter.generated.h"

class AFortPlayerControllerSpectating;
class AFortPlayerPawn;
class AFortPlayerState;
class AFortPlayerStateAthena;
class UStaticMeshComponent;
enum class ESpectatorCameraType : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortSpectatorPlayerHighlighter : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BeingFollowedBySpectatorCamChanged(bool bInBeingFollowedBySpectatorCam);

	UFUNCTION(BlueprintImplementableEvent)
	void FirstPlaceHighlightEnabledChanged(bool bInFirstPlaceHighlightEnabled);

	UFUNCTION(BlueprintPure, Category="SpectatorPlayerHighLighter")
	ESpectatorCameraType GetCurrentSpectatorCameraType() const;

	UFUNCTION()
	void HandleFirstPlaceHighlightEnabledChanged(bool bFirstPlaceHighlightEnabled);

	UFUNCTION()
	void HandleFollowedPlayerChanged(AFortPlayerControllerSpectating* SpectatorPC, AFortPlayerState* NewFollowedPlayer);

	UFUNCTION()
	void HandleHighlightedPlayerDeadStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDead);

	UFUNCTION()
	void HandleHighlightedPlayerDisconnectedChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDisconnected);

	UFUNCTION()
	void HandleHighlightedPlayerPawnChanged();

	UFUNCTION()
	void HandlePlayerOutlinesEnabledChanged(bool bOutlinesEnabled);

	UFUNCTION()
	void HandleSpectatorCameraTypeChanged(AFortPlayerControllerSpectating* SpectatorPC, ESpectatorCameraType NewCameraType);

	UFUNCTION(BlueprintImplementableEvent)
	void HighlightedPlayerPawnChanged(AFortPlayerPawn* NewPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void PlayerTeamColorChanged(const FLinearColor& TeamColor);

	UFUNCTION(BlueprintPure, Category="SpectatorPlayerHighlighter")
	bool ShouldBeVisible() const;

	UFUNCTION(BlueprintImplementableEvent)
	void SpectatorCameraTypeChanged(ESpectatorCameraType NewCameraType);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="SpectatorPlayerHighlighter", meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> CustomDepthOutlineMesh;

	UPROPERTY(BlueprintReadOnly, Category="SpectatorPlayerHighlighter")
	TObjectPtr<AFortPlayerStateAthena> HighlightedPlayerState;

	UPROPERTY(BlueprintReadOnly, Category="SpectatorPlayerHighlighter")
	bool bBeingFollowedBySpectatorCam;

	UPROPERTY(BlueprintReadOnly, Category="SpectatorPlayerHighlighter")
	bool bFirstPlaceHighlightEnabled;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPlayerHighlighter")
	EAttachmentRule HighlightedPlayerLocationAttachmentRule;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPlayerHighlighter")
	EAttachmentRule HighlightedPlayerRotationAttachmentRule;

	UPROPERTY(EditDefaultsOnly, Category="SpectatorPlayerHighlighter")
	EAttachmentRule HighlightedPlayerScaleAttachmentRule;

};

