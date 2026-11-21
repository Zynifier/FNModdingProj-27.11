// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/MathFwd.h"
#include "FortSqueegeeTypes.generated.h"

class UFortGameActivity;

UENUM(BlueprintType)
enum class ESqueegeeDataTypes : uint8
{
	GameActivity = 0,
	Weapons = 1,
	None = 2,
};

UENUM(BlueprintType)
enum class ESqueegeeText : uint8
{
	LobbyGameModeAction = 0,
	LobbyGameModeActionCabined = 1,
	GameModeInfoAction = 2,
	GameModeDetailsDisplayAction = 3,
	OptionSettingName = 4,
	OptionSettingDescription = 5,
	ActionSettingName = 6,
	ActionSettingDescription = 7,
	SidebarButton = 8,
};

UENUM(BlueprintType)
enum class ESqueegeeWidgetInjection : uint8
{
	None = 0,
	RatingTag = 1,
	RatingCard = 2,
	GameModeInfo = 3,
	PinModalInfo = 4,
	ManagementScreen = 5,
	ParentalControlsModal = 6,
	LockIcon = 7,
	VideoBumper = 8,
};

USTRUCT(BlueprintType)
struct FORTNITEUI_API FSqueegeeData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Squeegee Data")
	ESqueegeeDataTypes DataType;

};

USTRUCT(BlueprintType)
struct FSqueegeeStyleParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
	FVector2D IconSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
	FVector2D IconSkewSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
	int32 FontSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
	float PaddingSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Style")
	bool bShowDetails;

};

UCLASS()
class FORTNITEUI_API UFortSqueegeeWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetGameActivity(UFortGameActivity* GameActivity);

	UFUNCTION(BlueprintCallable)
	void ShowUnlockPinForActivity();

};

