// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/DeveloperSettings.h"
#include "FortQuestMapMarkerSettings.generated.h"

class UDataTable;
class UFortPlaylist;

USTRUCT(BlueprintType)
struct FFortMapMarkerTagNameData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Config, Category="FortMapMarkerTagNameData")
	FName TagName;

	UPROPERTY(EditAnywhere, Config, Category="FortMapMarkerTagNameData")
	TArray<FName> Maps;

};

USTRUCT(BlueprintType)
struct FFortMapMarkerUpdateCommandletFailedTagRecord : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortMapMarkerUpdateCommandletFailedTagRecord")
	FName TagName;

	UPROPERTY(VisibleAnywhere, Category="FortMapMarkerUpdateCommandletFailedTagRecord")
	int32 NumChildTagsAvailable;

	UPROPERTY(VisibleAnywhere, Category="FortMapMarkerUpdateCommandletFailedTagRecord")
	int32 NumChildTagsFound;

};

USTRUCT()
struct FFortMapQuestMapMarkerData
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Config, Category="QuestLocation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteGame.FortQuestTagToLocationDataRow"))
	TSoftObjectPtr<UDataTable> MapMarkerActorPositions;

	UPROPERTY(EditAnywhere, Config, Category="QuestLocation", meta=(RequiredAssetDataTags="RowStructure=/Script/FortniteEditor.FortMapMarkerUpdateCommandletFailedTagRecord"))
	TSoftObjectPtr<UDataTable> FailedMapMarkerActorPositions;

	UPROPERTY(EditAnywhere, Config, Category="FortMapQuestMapMarkerData")
	TSoftObjectPtr<UFortPlaylist> OverridePlaylistForPluginsActivation;

};

UCLASS(Config=MapMarkerSettings, DefaultConfig, meta=(DisplayName="Fortnite Quest Map Marker Settings"))
class UFortQuestMapMarkerSettings : public UDeveloperSettings
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Config, Category="QuestLocation")
	TMap<FName, FFortMapQuestMapMarkerData> QuestTagToLocationDataTables;

	UPROPERTY(EditAnywhere, Config, Category="QuestLocation")
	TArray<FFortMapMarkerTagNameData> QuestMapMarkerTagNamesData;

	UPROPERTY(EditAnywhere, Config, Category="FortQuestMapMarkerSettings")
	TSoftObjectPtr<UFortPlaylist> PlaylistForPluginsActivation;

};

