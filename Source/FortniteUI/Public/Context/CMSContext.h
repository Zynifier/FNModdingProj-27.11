// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Misc/DateTime.h"
#include "BlueprintContextBase.h"
#include "FortDynamicBackgroundKey.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "Media/VideoWidgetConfig.h"
#include "Online/FortMatchmakingUtilityDataTypes.h"
#include "Store/FortPurchaseTypes.h"
#include "CMSContext.generated.h"

class UFortPlayerSurveyInterpreter;
class UTexture2D;

USTRUCT()
struct FAthenaShopCarouselItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FText PreviewTitle;

	UPROPERTY()
	FText FullTitle;

	UPROPERTY()
	FString TileImage;

	UPROPERTY()
	FString VideoString;

	UPROPERTY()
	FString OfferId;

	UPROPERTY()
	int32 LandingPriority;

	UPROPERTY()
	EItemShopNavigationAction Action;

	UPROPERTY()
	bool bHidden;

};

USTRUCT(BlueprintType)
struct FDynamicBackground
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DynamicBackground")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="DynamicBackground")
	FString __locale;

	UPROPERTY(BlueprintReadOnly, Category="DynamicBackground")
	EDynamicBackgroudKey Key;

	UPROPERTY(BlueprintReadOnly, Category="DynamicBackground")
	FString BackgroundImage;

	UPROPERTY(BlueprintReadOnly, Category="DynamicBackground")
	FString Stage;

};

USTRUCT()
struct FAthenaShopSection
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName SectionId;

	UPROPERTY()
	FText SectionDisplayName;

	UPROPERTY()
	bool bSortOffersByOwnership;

	UPROPERTY()
	bool bShowIneligibleOffers;

	UPROPERTY()
	bool bShowIneligibleOffersIfGiftable;

	UPROPERTY()
	bool bShowTimer;

	UPROPERTY()
	bool bEnableToastNotification;

	UPROPERTY()
	int32 LandingPriority;

	UPROPERTY()
	FDynamicBackground SectionBackground;

	UPROPERTY()
	bool bHidden;

	UPROPERTY()
	FDateTime DateToResetItemShopLanding;

};

USTRUCT(BlueprintType)
struct FAthenaShopSpecialOffer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bSpecialOfferEnabled;

	UPROPERTY()
	FVideoWidgetConfig SpecialOfferVideo;

};

USTRUCT(BlueprintType)
struct FCreativeAdData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	FString Header;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	FString Sub_Header;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	FString Description;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	FString Creator_Name;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	FString Island_Code;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	EFortCreativeAdType Ad_Type;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	EFortCreativeAdColorPreset Ad_Color_Preset;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdData")
	FString Image;

};

USTRUCT(BlueprintType)
struct FCreativeAdJsonObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeAdJsonObject")
	TArray<FCreativeAdData> Ads;

};

USTRUCT(BlueprintType)
struct FCreativeAdSource
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeAdSource")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdSource")
	FString __locale;

	UPROPERTY(BlueprintReadOnly, Category="CreativeAdSource")
	FCreativeAdJsonObject Ad_Info;

};

USTRUCT(BlueprintType)
struct FShowdownTournamentData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Tournament_Display_Id;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Title_Line_1;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Title_Line_2;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Schedule_Info;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Poster_Front_Image;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Poster_Back_Image;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Flavor_Description;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Details_Description;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Short_Format_Title;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Long_Format_Title;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Background_Title;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	int32 Pin_Score_Requirement;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FText Pin_Earned_Text;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Base_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Primary_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Secondary_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Highlight_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Title_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Shadow_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Background_Left_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Background_Right_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Background_Text_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FLinearColor Poster_Fade_Color;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Playlist_Tile_Image;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Loading_Screen_Image;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Style_Info_Id;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	FString Alert_Text;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentData")
	EFortTournamentAlertType AlertType;

};

USTRUCT(BlueprintType)
struct FShowdownTournamentJsonObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentJsonObject")
	TArray<FShowdownTournamentData> Tournaments;

};

USTRUCT(BlueprintType)
struct FShowdownTournamentSource
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentSource")
	FShowdownTournamentJsonObject Tournament_Info;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentSource")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="ShowdownTournamentSource")
	FString _locale;

};

USTRUCT(BlueprintType)
struct FSubgameDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FText Title;

	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FText Description;

	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FText SpecialMessage;

	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FText StandardMessageLine1;

	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FText StandardMessageLine2;

	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FString Image;

	UPROPERTY(BlueprintReadOnly, Category="SubgameDisplayData")
	FLinearColor Color;

};

USTRUCT(BlueprintType)
struct FSubgameScreenSource
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SubgameScreenSource")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="SubgameScreenSource")
	FString __locale;

	UPROPERTY(BlueprintReadOnly, Category="SubgameScreenSource")
	FSubgameDisplayData Creative;

	UPROPERTY(BlueprintReadOnly, Category="SubgameScreenSource")
	FSubgameDisplayData SaveTheWorld;

	UPROPERTY(BlueprintReadOnly, Category="SubgameScreenSource")
	FSubgameDisplayData BattleRoyale;

};

USTRUCT(BlueprintType)
struct FCmsJsonMessages
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CmsJsonMessages")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="CmsJsonMessages")
	FString _locale;

	UPROPERTY(BlueprintReadOnly, Category="CmsJsonMessages")
	FShowdownTournamentSource TournamentInformation;

	UPROPERTY(BlueprintReadOnly, Category="CmsJsonMessages")
	FSubgameScreenSource SubgameInfo;

	UPROPERTY(BlueprintReadOnly, Category="CmsJsonMessages")
	FCreativeAdSource CreativeAds;

};

USTRUCT(BlueprintType)
struct FDynamicBackgrounds
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<FDynamicBackground> Backgrounds;

};

USTRUCT(BlueprintType)
struct FDynamicBackgroundsSource
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DynamicBackgroundsSource")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="DynamicBackgroundsSource")
	FString __locale;

	UPROPERTY()
	FString LastModified;

	UPROPERTY()
	FDynamicBackgrounds Backgrounds;

};

USTRUCT(BlueprintType)
struct FFortShowdownScoringRuleDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleDisplayInfo")
	FName Name;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleDisplayInfo")
	FText Description;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleDisplayInfo")
	FText PosterDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleDisplayInfo")
	FText PosterIntervalDescription;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleDisplayInfo")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(BlueprintReadOnly, Category="FortShowdownScoringRuleDisplayInfo")
	bool bShowScoreToastNotifications;

};

USTRUCT()
struct FPlatformPurchaseMessaging
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FPlatformPurchaseErrorCodeMessages ErrorCodeMessages;

};

USTRUCT(BlueprintType)
struct FSocialEventJSON
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SocialEventJSON")
	int32 event_id;

	UPROPERTY(BlueprintReadOnly, Category="SocialEventJSON")
	FText title;

	UPROPERTY(BlueprintReadOnly, Category="SocialEventJSON")
	FDateTime starts_at_utc;

};

USTRUCT(BlueprintType)
struct FSocialEventsJsonObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SocialEventsJsonObject")
	TArray<FSocialEventJSON> Events;

};

USTRUCT(BlueprintType)
struct FSocialEventsSource
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SocialEventsSource")
	FString _title;

	UPROPERTY(BlueprintReadOnly, Category="SocialEventsSource")
	FString __locale;

	UPROPERTY()
	FString LastModified;

	UPROPERTY()
	FSocialEventsJsonObject SocialEvents;

};

UCLASS()
class FORTNITEUI_API UCMSContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FCreativeAdSource GetLatestCreativeAds();

	UFUNCTION(BlueprintPure)
	FDynamicBackgroundsSource GetLatestDynamicBackgrounds() const;

	UFUNCTION(BlueprintCallable)
	const FSubgameScreenSource GetLatestSubgameInfo();

	UFUNCTION(BlueprintPure)
	const FFortShowdownScoringRuleDisplayInfo GetScoringRuleDisplayInfo(const FName RuleName) const;

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Survival Title And Body Message"))
	bool GetSurvivalCMSText(FText& Title, FText& Body) const;

	UFUNCTION(BlueprintPure)
	bool HasScoringRuleDisplayInfo(const FName RuleName) const;

	UFUNCTION(BlueprintPure)
	bool IsNewPlaylistInformationAvailable() const;

	UFUNCTION(BlueprintCallable)
	void MarkNewsAsShown();

	UFUNCTION(BlueprintCallable)
	void MarkPlaylistInformationAsViewed();

	UFUNCTION(BlueprintPure)
	bool ShouldAutoOpenNews() const;

private:
	UPROPERTY(Transient)
	FCmsJsonMessages CachedCmsMessages;

	UPROPERTY(Transient)
	TObjectPtr<UFortPlayerSurveyInterpreter> PlayerSurveyInterpreter;

};

