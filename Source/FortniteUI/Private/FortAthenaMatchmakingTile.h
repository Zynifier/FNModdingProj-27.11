// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortPlaylistTypes.h"
#include "Online/FortMatchmakingUtilityDataTypes.h"
#include "FortAthenaMatchmakingTile.generated.h"

class UCommonBorder;
class UCommonTextBlock;
class UEpicCMSImage;
class UFortActiveFriendsViolator;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaMatchmakingTile : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCMSDataUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void PlaylistChanged(const FPlaylistFrontEndData& PlaylistToRepresent);

	UFUNCTION(BlueprintCallable)
	void PopulateTextFieldsFromCMS();

	UFUNCTION(BlueprintImplementableEvent)
	void SetDefaultImage();

	UFUNCTION(BlueprintImplementableEvent)
	void SetTileSize(int32 NumRowTiles);

	UFUNCTION(BlueprintImplementableEvent)
	void TilePlaylistSetAsMatchmakingPlaylist();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTileAvailability(bool Available);

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEpicCMSImage> GameModeImage;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> AdSpace;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> AdText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> SpecialAdText;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> GameModeName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAthenaMatchmakingTile", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> SubGameModeName;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMatchmakingTile")
	int32 BorderDisplayStyle;

	UPROPERTY(BlueprintReadOnly, Category="FortAthenaMatchmakingTile")
	FAthenaPlaylistEntry CMSPlaylistEntry;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortActiveFriendsViolator> Violator_ActiveFriends;

private:
	UPROPERTY(Transient)
	FPlaylistFrontEndData TilePlaylistData;

};

