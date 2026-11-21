// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativeServersView.generated.h"

class UCommonButtonGroupLegacy;
class UFortCreativeServerInfo;
class UFortCreativeServerOptionTile;
class UFortSocialUser;
class UScrollBox;
class UTexture;

UENUM(BlueprintType)
enum class EFortCreativeServerPrivacySetting : uint8
{
	Unknown = 0,
	Private = 1,
	Public = 2,
};

USTRUCT(BlueprintType)
struct FFortCreativeServerDisplayOption : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeServerDisplayOption")
	TSoftObjectPtr<UTexture> Image;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeServerDisplayOption")
	FLinearColor Color;

};

UCLASS(BlueprintType)
class UFortCreativeServerInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	int32 CurrentPlayerCount;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	int32 MaxPlayerCount;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	TArray<FString> MatchFriendsList;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	FString OwnerName;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	TObjectPtr<UFortSocialUser> FriendInMatch;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	EFortCreativeServerPrivacySetting PrivacySetting;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	bool IsNewServer;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServerInfo")
	FText ServerTypeText;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeServersView : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCreativeServerListRefreshed();

	UPROPERTY(EditAnywhere, Category="FortCreativeServersView")
	int32 MaxSuggestedServers;

	UPROPERTY(EditAnywhere, Category="FortCreativeServersView")
	bool bShowDebugServers;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="FortCreativeServersView", meta=(DesignerRebuild="TRUE"))
	TSubclassOf<UFortCreativeServerOptionTile> TileItemClass;

protected:
	UFUNCTION(BlueprintCallable)
	void NavigateServerLeft();

	UFUNCTION(BlueprintCallable)
	void NavigateServerRight();

	UFUNCTION(BlueprintCallable)
	void RefreshServerList();

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServersView")
	TObjectPtr<UCommonButtonGroupLegacy> ServerButtonGroup;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeServersView", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> ScrollBox_ServerList;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeServersView")
	TArray<TObjectPtr<UFortCreativeServerInfo>> ServerList;

};

