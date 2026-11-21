// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "Misc/DateTime.h"
#include "Styling/SlateBrush.h"
#include "PictureInPicturePartnerData.generated.h"

class UCommonActivatableWidget;
class UFortMediaSubtitlesPlayer;
class UFortStreamMediaSource;
class UImage;
class ULocalizedOverlays;
class UMaterialInterface;
class UMediaPlayer;
class UMediaSoundComponent;
class UMediaTexture;
class USoundClass;
class USoundMix;
class USoundSubmixBase;
class USubtitleDisplayOptions;

UENUM(BlueprintType)
enum class PictureInPictureAction : uint8
{
	NEXT = 0,
	PREVIOUS = 1,
	PLAY = 2,
	PAUSE = 3,
	PLAYPAUSE = 4,
	LIKE = 5,
	REPORT = 6,
	EXIT = 7,
	UNLIKE = 8,
	TOGGLELIKE = 9,
	TOGGLEFULLSCREEN = 10,
	//Leave as last

	Count = 11 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPictureActionCallbackEvent, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPictureInPictureActionEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPictureInPictureActionFiredEvent, FPictureInPictureActionCallbackEvent, InCallback);

USTRUCT(BlueprintType)
struct PICTUREINPICTUREDESCRIPTORS_API FPIPVideoPlayerAssetConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<UMediaTexture> VideoTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<UMediaPlayer> VideoPlayer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<UMaterialInterface> VideoMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<UMaterialInterface> ThumbnailMaterial;

	UPROPERTY(EditAnywhere, Category="PIPVideoPlayerAssetConfig")
	FVector2D LoadingScreenSize;

	UPROPERTY(EditAnywhere, Category="PIPVideoPlayerAssetConfig")
	FVector2D LoadingScreenPosition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<UFortStreamMediaSource> MediaSource;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMediaSoundComponent> SoundComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<USoundClass> SoundClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<USoundMix> ActiveSoundMix;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<USoundSubmixBase> DefaultSubmix;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<USoundSubmixBase> LicensedSubmix;

	UPROPERTY(EditAnywhere, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<UFortMediaSubtitlesPlayer> SubtitlePlayer;

	UPROPERTY(EditAnywhere, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<ULocalizedOverlays> SubtitleOverlays;

	UPROPERTY(EditAnywhere, Category="PIPVideoPlayerAssetConfig")
	TObjectPtr<USubtitleDisplayOptions> SubtitleDisplayOptions;

};

USTRUCT()
struct PICTUREINPICTUREDESCRIPTORS_API FPIPVideoPlayerConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString MimeType;

	UPROPERTY()
	FString BlurlVUID;

	UPROPERTY()
	bool bLoopEnabled;

	UPROPERTY()
	bool bAutoPlay;

	UPROPERTY()
	FString VideoURL;

	UPROPERTY()
	bool bShareBlocked;

	UPROPERTY()
	FDateTime EventStartTime;

};

USTRUCT(BlueprintType)
struct PICTUREINPICTUREDESCRIPTORS_API FPictureInPictureActionConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PictureInPictureActionConfig")
	PictureInPictureAction ActionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PictureInPictureActionConfig")
	FSlateBrush ActionBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="PictureInPictureActionConfig")
	FText ActionText;

};

UCLASS(BlueprintType)
class PICTUREINPICTUREDESCRIPTORS_API UPictureInPicturePartnerDataAsset : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePartnerDataAsset")
	FString PartnerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="PictureInPicturePartnerDataAsset", meta=(EditInline="true"))
	TObjectPtr<UImage> ClientImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePartnerDataAsset")
	int32 MediaHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePartnerDataAsset")
	int32 MediaWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePartnerDataAsset")
	TSubclassOf<UCommonActivatableWidget> MetadataOverlayClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePartnerDataAsset")
	TArray<FPictureInPictureActionConfig> Actions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PictureInPicturePartnerDataAsset")
	FPIPVideoPlayerAssetConfig AssetConfig;

};

