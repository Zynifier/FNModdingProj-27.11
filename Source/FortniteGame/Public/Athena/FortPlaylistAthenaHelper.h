// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortPlaylistAthenaHelper.generated.h"

class UFortPlaylistAthena;
enum class EAthenaGamePhaseStep : uint8;
enum class EFortPlaylistType : uint8;

UCLASS()
class UFortPlaylistAthenaHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool CanExperienceSettingsBeDeleted(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static float GetEndGameReturnToMatchmakingOriginDelay(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static EFortPlaylistType GetPlaylistType(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool HasCreativeTag(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool HasTag(const UFortPlaylistAthena* Playlist, const FGameplayTag& InTag);

	UFUNCTION(BlueprintCallable)
	static bool IsAnyCreativePlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsArnoldGameplayPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsArnoldLobbyPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsArnoldPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsCreativeLTMPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsCreativeMMPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsCreativeModePlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsCreativeRoyalePlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsCreativeUtilitySpawningAllowedPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsExperiencePlayOnly(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsExperienceUGCCore(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsGamePhaseNotificationSkipped(const UFortPlaylistAthena* Playlist, EAthenaGamePhaseStep GamePhaseToSkip);

	UFUNCTION(BlueprintCallable)
	static bool IsGuidedTutorialPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsLargePreviewDisabledOnMobile(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsNoBuildBRPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsPapayaPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsPlayerTriggeredRespawnAllowed(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsPlaygroundModePlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsSpatialGameplayExperience(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsUGCCreatePlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsVKEditPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool IsVKPlayPlaylist(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool NeedsToDownloadAdditionalContentBeforeJoin(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool RequiresAdditionalContent(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool ShouldBlockQuestProgressReport(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool ShouldEnterSpawningStartup(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool ShouldErrorOnAdditionalContentFailure(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool ShouldReturnToMatchmakingOriginOnMatchEnd(const UFortPlaylistAthena* Playlist);

	UFUNCTION(BlueprintCallable)
	static bool ShouldSpawnCreativeManagers(const UFortPlaylistAthena* Playlist);

};

