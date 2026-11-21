// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeDataChannelTypes.h"
#include "ElectraDataChannelTarget.h"
#include "CreativeDataChannelTarget_FN.generated.h"

UCLASS(Config=Creative, BlueprintType, Blueprintable, ClassGroup=("Creative"))
class CREATIVEDATACHANNELTRIGGERRUNTIME_API ACreativeDataChannelTargetFN : public AElectraDataChannelTarget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	int32 VersionByte;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCInt VersionByteTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventIntRep VersionByteEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString LeaderBoard;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	int64 StormCircleSize;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCLargeInt StormCircleSizeTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventLargeIntRep StormCircleSizeEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	TArray<float> StormCircleLocation;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCFloatArray StormCircleLocationTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventFloatArrayRep StormCircleLocationEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString PlayerLocation;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCStringFloatArrayMap PlayerLocationTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventFloatArrayMapRep PlayerLocationEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString ArenaPointLeaderBoard;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCStringStringMap ArenaPointLeaderBoardTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventStringMapRep ArenaPointLeaderBoardEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString CashCupDataAllTimeEarners;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCStringFloatMap CashCupDataAllTimeEanersTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventFloatMapRep CashCupDataAllTimeEarnersEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString MythicBossEliminatedPlayer;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCString MythicBossEliminatedPlayerTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventStringRep MythicBossEliminatedPlayerEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString MythicWeaponPlayer;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCString MythicWeaponPlayerTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCEventStringRep MythicWeaponPlayerEvent;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FString PlayerInfo;

	UPROPERTY(BlueprintReadOnly, Category="CreativeDataChannelTargetFN")
	FCDCStringArray PlayerInfoTracker;

	UPROPERTY(BlueprintAssignable)
	FCDCStringArrayRep PlayerInfoEvent;

};

