// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Building/BuildingProp.h"
#include "BuildingPropMusicPlayer.generated.h"

class UAudioComponent;
class UDataTable;
class UObject;
class USoundBase;

UENUM(BlueprintType)
enum class EMusicTrackPlayback : uint8
{
	Disabled = 0,
	Enabled = 1,
};

USTRUCT(BlueprintType)
struct FMusicPlayerData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="MusicPlayerData")
	int32 SongIndex;

	UPROPERTY(BlueprintReadOnly, Category="MusicPlayerData")
	float ServerTimeSongStarted;

};

USTRUCT(BlueprintType)
struct FMusicTrackData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	bool Enabled;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	TSoftObjectPtr<USoundBase> MusicTrackPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Music")
	FText TrackName;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingPropMusicPlayer : public ABuildingProp
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	UDataTable* GetMusicDataTable() const;

	UFUNCTION(BlueprintNativeEvent)
	FString GetSavedTrackName() const;

	UFUNCTION(BlueprintNativeEvent)
	void LoadThenPlaySong();

	UFUNCTION()
	void OnRep_PlayingSongData();

	UFUNCTION(BlueprintCallable)
	void StartSongForOptionsChange();

	UPROPERTY(EditAnywhere, Category="Music")
	uint8 bCheckAlternateHotfixValue : 1;

	UPROPERTY(EditAnywhere, Category="Music")
	uint8 bPlayingByDefault : 1;

	UPROPERTY(EditAnywhere, Category="Music")
	uint8 bPlayRandomSong : 1;

	UPROPERTY(Transient)
	TArray<int32> AvailableSongIndices;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Music")
	TObjectPtr<UDataTable> MusicTrackTable;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="BuildingPropMusicPlayer")
	TArray<TSoftObjectPtr<UObject>> MusicArray;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_PlayingSongData, Category="BuildingPropMusicPlayer")
	FMusicPlayerData PlayingSongData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="BuildingPropMusicPlayer", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<UAudioComponent> SongAudioComponent;

	UPROPERTY(SaveGame)
	FString SavedTrackName;

	UPROPERTY(BlueprintReadWrite, SaveGame, Category="BuildingPropMusicPlayer")
	EMusicTrackPlayback PlaybackType;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Music|EditorOnly")
	bool bIgnoreHotfixCheckInEditor;
#endif

};

