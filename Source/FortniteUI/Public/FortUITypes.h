// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "Engine/DataTable.h"
#include "GameplayEffectTypes.h"
#include "FortErrorSeverity.h"
#include "FortMultiSize.h"
#include "FortUITypes.generated.h"

class UCommonActivatableWidget;
class UFortAthenaMatchmakingWidgetLegacy;
class UFortHero;
class UTexture2D;
class UUserWidget;

UENUM(BlueprintType)
enum class EFortAnimSpeed : uint8
{
	Instant = 0,
	Fast = 1,
	Normal = 2,
};

UENUM(BlueprintType)
enum class EFortBangSize : uint8
{
	XXS = 0,
	XS = 1,
	S = 2,
	M = 3,
	L = 4,
	XL = 5,
};

UENUM(BlueprintType)
enum class EFortBuffState : uint8
{
	NoChange = 0,
	Better = 1,
	Worse = 2,
};

UENUM(BlueprintType)
enum class EFortClampState : uint8
{
	NoClamp = 0,
	MinClamp = 1,
	MaxClamp = 2,
};

UENUM(BlueprintType)
enum class EFortComparisonType : uint8
{
	None = 0,
	HigherValue = 1,
	LowerValue = 2,
	Upgrade = 3,
};

UENUM()
namespace EFortInventoryContext
{
	enum Type
	{
		Game = 0,
		Lobby = 1,
		FrontEnd = 2,
		Pickup = 3,
	};
}

UENUM(BlueprintType)
enum class EFortItemCardSize : uint8
{
	XXS = 0,
	XS = 1,
	Wide_S = 2,
	S = 3,
	M = 4,
	L = 5,
	Wide_L = 6,
	XL = 7,
	XXL = 8,
};

UENUM(BlueprintType, meta=(Category="Fortnite UI"))
enum class EFortSocialPanelTab : uint8
{
	PartyInvitations = 0,
	Friends = 1,
	RecentPlayers = 2,
	Max = 3 UMETA(Hidden),
};

UENUM(BlueprintType, meta=(Category="Fortnite UI"))
enum class EFortSocialPanelType : uint8
{
	Join = 0,
	Invite = 1,
	Max = 2 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortStatValueDisplayType : uint8
{
	BasicPaired = 0,
	BasicSingle = 1,
	Unique = 2,
	ElementalFire = 3,
	ElementalIce = 4,
	ElementalElectric = 5,
};

UENUM(BlueprintType)
enum class EFortStoreState : uint8
{
	Error = 0,
	Closed = 1,
	CardPackStore = 2,
	CurrencyStore = 3,
	WebPayment = 4,
	PurchaseOpen = 5,
	PackOpen = 6,
	CardEnter = 7,
	CardBackReveal = 8,
	CardFlip = 9,
	CardFrontReveal = 10,
	CardExit = 11,
	SummaryAdd = 12,
	PackDestroy = 13,
	Summary = 14,
	PresentChoice = 15,
	ChoiceMade = 16,
	SummaryAddTransition = 17,
	MAX_None = 18 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortToastType : uint8
{
	Default = 0,
	Subdued = 1,
	Impactful = 2,
};

UENUM(BlueprintType)
enum class EFortTutorialGlowType : uint8
{
	None = 0,
	Look = 1,
	Click = 2,
};

UENUM(BlueprintType)
enum class EFortUIState : uint8
{
	Invalid = 0,
	Login = 1,
	JoinServer = 2,
	SubgameSelect = 3,
	FrontEnd = 4,
	InGame_Custom = 5,
	UNUSED = 6,
	InGame_STW = 7,
	Cinematic = 8,
	InGame_BR = 9,
	AthenaSpectator = 10,
	Replay = 11,
	InGame_STW_Custom = 12,
	MAX = 13 UMETA(Hidden),
};

UENUM()
enum class EItemShopNavigationAction : uint8
{
	None = 0,
	ShowOfferDetails = 1,
	NavigateToOffer = 2,
};

UENUM(BlueprintType)
enum class EModalContainerSize : uint8
{
	ExtraSmall = 0,
	Small = 1,
	Medium = 2,
	Large = 3,
	Max = 4 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class ENotificationResult : uint8
{
	Confirmed = 0,
	Declined = 1,
	Unknown = 2,
};

UENUM(BlueprintType)
enum class ENotificationType : uint8
{
	Basic = 0,
	Friends = 1,
};

UENUM()
enum class EPlayerReportReasons : uint8
{
	// STW reasons:

	None = 0,
	Communication = 1,
	Offensive = 2,
	AFK = 3,
	IgnoringObjective = 4,
	Harassment = 5,
	Exploiting = 6,
	TradeScam = 7,
	// BR Reasons:

	CommunicationsAbuse = 8,
	OffensiveName = 9,
	TeamingUpWithEnemies = 10,
	//Harassment, also in STW group above

	InappropriateContent = 11,
	ExploitingOrHacking = 12,
	Harassment_Threatening = 13,
	Harassment_Annoying = 14,
	Harassment_Selling = 15,
	Harassment_Verbal = 16,
	Harassment_GameBehavior = 17,
};

UENUM(BlueprintType)
enum class ESubscriptionContentTab : uint8
{
	SubscriptionManagementScreen = 0,
	ProgressiveItemScreen = 1,
	TemporaryItemsScreen = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBasicDynamicMulticastDelegate);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FRecruitHeroWidgetFinishedDelegate, UFortHero*, NewHero);

USTRUCT(BlueprintType)
struct FAthenaWinnerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Winner Info")
	FString BigNameWinnerName;

	UPROPERTY(BlueprintReadOnly, Category="Winner Info")
	TArray<FString> WinnerNames;

};

USTRUCT(BlueprintType)
struct FFortAttributeModifierDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortAttributeModifierDisplayData")
	FGameplayAttribute Attribute;

	UPROPERTY(BlueprintReadOnly, Category="FortAttributeModifierDisplayData")
	float Value;

	UPROPERTY(BlueprintReadOnly, Category="FortAttributeModifierDisplayData")
	TEnumAsByte<EGameplayModOp::Type> ModifierType;

	UPROPERTY(BlueprintReadOnly, Category="FortAttributeModifierDisplayData")
	FGameplayTagRequirements SourceTags;

	UPROPERTY(BlueprintReadOnly, Category="FortAttributeModifierDisplayData")
	FGameplayTagRequirements TargetTags;

};

USTRUCT(BlueprintType)
struct FFortDisplayAttribute
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	FGameplayAttribute Attribute;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	FText Label;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	FText Value;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	FText HoverText;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	float NumericValue;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	EFortStatValueDisplayType DisplayType;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	EFortBuffState BuffState;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	EFortClampState ClampState;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayAttribute")
	EFortComparisonType ComparisonType;

};

USTRUCT(BlueprintType)
struct FFortDisplayModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FortDisplayModifier")
	FText Label;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayModifier")
	FText Value;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayModifier")
	EFortStatValueDisplayType DisplayType;

	UPROPERTY(BlueprintReadWrite, Category="FortDisplayModifier")
	EFortBuffState BuffState;

};

USTRUCT(BlueprintType)
struct FFortErrorInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortErrorInfo")
	FText Operation;

	UPROPERTY(BlueprintReadOnly, Category="FortErrorInfo")
	FText ErrorMessage;

	UPROPERTY(BlueprintReadOnly, Category="FortErrorInfo")
	FString ErrorCode;

	UPROPERTY(BlueprintReadOnly, Category="FortErrorInfo")
	EFortErrorSeverity ErrorSeverity;

	UPROPERTY(BlueprintReadOnly, Category="FortErrorInfo")
	FText ContinueButtonText;

};

USTRUCT(BlueprintType)
struct FFortHealthyGamingData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	float HealthWarningToastInterval;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	FText HealthWarningToastDescriptionFormat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	FText HealthWarningScreenText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	FText GameplayRestrictionText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	float GameplayRestrictionWarningTimeOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	FText AntiAddictionTotalDescriptionFormat;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	bool bUsePlayerTimeLimitSystem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHealthyGamingData")
	TArray<TSoftObjectPtr<UTexture2D>> RatingIcons;

};

USTRUCT(BlueprintType)
struct FFortSquadIconData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FFortMultiSizeBrush Brush;

};

USTRUCT(BlueprintType)
struct FFortToastDisplayInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="Callout")
	FText Header;

	UPROPERTY(BlueprintReadWrite, Category="Callout")
	FText Body;

	UPROPERTY(BlueprintReadWrite, Category="Callout")
	TSoftObjectPtr<UTexture2D> Image;

	UPROPERTY(BlueprintReadWrite, Category="Callout")
	EFortToastType Type;

};

USTRUCT(BlueprintType)
struct FGenericEmptyPayload
{
	GENERATED_BODY()

};

USTRUCT(BlueprintType)
struct FMatchmakingUIOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="MatchmakingUIOverride")
	TSoftClassPtr<UCommonActivatableWidget> SoftMatchmakingOptionsClass;

	UPROPERTY(EditAnywhere, Category="MatchmakingUIOverride")
	TSoftClassPtr<UCommonActivatableWidget> SoftMatchmakingOptionsClassV2;

	UPROPERTY(EditAnywhere, Category="MatchmakingUIOverride")
	TSoftClassPtr<UFortAthenaMatchmakingWidgetLegacy> SoftLobbyMatchmakingWidgetClass;

};

USTRUCT(BlueprintType)
struct FOpenCustomUIContext
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="OpenCustomUIContext", meta=(EditInline="true"))
	TObjectPtr<UUserWidget> ContextWidget;

};

