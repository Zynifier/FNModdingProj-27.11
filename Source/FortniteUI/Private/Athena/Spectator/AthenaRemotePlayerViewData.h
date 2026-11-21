// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "AthenaRemotePlayerViewData.generated.h"

class AActor;
class AFortPlayerPawn;
class AFortPlayerStateAthena;
class AFortWeapon;
class UAthenaRemotePlayerViewData;

UCLASS(BlueprintType)
class UAthenaRemotePlayerViewData : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FBoolDelegate, UAthenaRemotePlayerViewData*, PlayerData, bool, BoolParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FIntDelegate, UAthenaRemotePlayerViewData*, PlayerData, int32, IntParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLinearColorDelegate, UAthenaRemotePlayerViewData*, PlayerData, FLinearColor, ColorParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPawnDelegate, UAthenaRemotePlayerViewData*, PlayerData, AFortPlayerPawn*, PawnParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FPlayerStateDelegate, UAthenaRemotePlayerViewData*, PlayerData, AFortPlayerStateAthena*, PlayerState);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStringDelegate, UAthenaRemotePlayerViewData*, PlayerData, FString, StringParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FTwoFloatDelegate, UAthenaRemotePlayerViewData*, PlayerData, float, FloatParam, float, FloatParamMax);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUInt8Delegate, UAthenaRemotePlayerViewData*, PlayerData, uint8, IntParam);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWeaponDelegate, UAthenaRemotePlayerViewData*, PlayerData, AFortWeapon*, WeaponParam);

public:
	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Current Weapon"))
	AFortWeapon* GetCurrentWeapon() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Distance To Storm"))
	int32 GetDistanceToStorm() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Health"))
	void GetHealth(float& Health, float& HealthMax) const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Health %"))
	float GetHealthPercent() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="In Aircraft"))
	bool GetInAircraft() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Being Revived"))
	bool GetIsBeingRevived() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is DBNO"))
	bool GetIsDBNO() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Dead"))
	bool GetIsDead() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Disconnected"))
	bool GetIsDisconnected() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Driving Vehicle"))
	bool GetIsDrivingVehicle() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Eliminated"))
	bool GetIsEliminated() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="In Followed Player"))
	bool GetIsFollowedPlayer() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is In Relevancy"))
	bool GetIsInRelevancy() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Is Replay Relevancy Player"))
	bool GetIsReplayRelevancyPlayer() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Kill Score"))
	int32 GetKillScore() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Location"))
	FString GetLocation() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Material Count"))
	int32 GetMaterialCount() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Overshield"))
	void GetOvershield(float& Overshield, float& OvershieldMax) const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Overshield %"))
	float GetOvershieldPercent() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Place"))
	int32 GetPlace() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Player Name"))
	FString GetPlayerName() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Player Pawn"))
	AFortPlayerPawn* GetPlayerPawn() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Player State"))
	AFortPlayerStateAthena* GetPlayerState() const;

	UFUNCTION()
	FUniqueNetIdRepl GetPlayerUID() const;

	UFUNCTION(BlueprintPure)
	int32 GetSessionRank() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Shield"))
	void GetShield(float& Shield, float& ShieldMax) const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Shield %"))
	float GetShieldPercent() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Team Number"))
	uint8 GetSquadId() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Team Color"))
	FLinearColor GetTeamColor() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Vehicle"))
	AActor* GetVehicle() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Vehicle Health"))
	float GetVehicleHealth() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Vehicle Health %"))
	float GetVehicleHealthPercent() const;

	UFUNCTION(BlueprintPure, meta=(CompactNodeTitle="Vehicle Max Health"))
	float GetVehicleMaxHealth() const;

	UFUNCTION()
	void SetPlayerState(AFortPlayerStateAthena* InPlayerState);

	UFUNCTION()
	void UpdateDistanceToStorm();

	UFUNCTION()
	void UpdatePlayerPawn();

	UPROPERTY(BlueprintAssignable)
	FPlayerStateDelegate OnPlayerStateChanged;

	UPROPERTY(BlueprintAssignable)
	FLinearColorDelegate OnTeamColorChanged;

	UPROPERTY(BlueprintAssignable)
	FUInt8Delegate OnSquadIdChanged;

	UPROPERTY(BlueprintAssignable)
	FStringDelegate OnPlayerNameChanged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnKillScoreChanged;

	UPROPERTY(BlueprintAssignable)
	FStringDelegate OnLocationChanged;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnHealthHealed;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnHealthDamaged;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnShieldHealed;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnShieldDamaged;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnOvershieldHealed;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnOvershieldDamaged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnDBNOStateChanged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnDeadStateChanged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnBeingRevivedStateChanged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnDisconnectedChanged;

	UPROPERTY(BlueprintAssignable)
	FPawnDelegate OnPlayerPawnChanged;

	UPROPERTY(BlueprintAssignable)
	FWeaponDelegate OnWeaponChanged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnDistanceToStormChanged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnPlaceChanged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnMaterialCountChanged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnIsInRelevancyChanged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnIsFollowedPlayerChanged;

	UPROPERTY(BlueprintAssignable)
	FBoolDelegate OnIsReplayRelevancyPlayerChanged;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnVehicleHealthHealed;

	UPROPERTY(BlueprintAssignable)
	FTwoFloatDelegate OnVehicleHealthDamaged;

	UPROPERTY(BlueprintAssignable)
	FIntDelegate OnSessionRankChanged;

private:
	UFUNCTION()
	void ForwardOnBeingRevivedStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsBeingRevived);

	UFUNCTION()
	void ForwardOnDBNOStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDBNO);

	UFUNCTION()
	void ForwardOnDeadStateChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDead);

	UFUNCTION()
	void ForwardOnDisconnectedChanged(AFortPlayerStateAthena* InPlayerState, bool bInIsDisconnected);

	UFUNCTION()
	void ForwardOnHitPointsStateChanged(AFortPlayerStateAthena* InPlayerState, float InHealth, float InHealthMax, float InShield, float InShieldMax);

	UFUNCTION()
	void ForwardOnKillScoreChanged(AFortPlayerStateAthena* InPlayerState, int32 InKillScore);

	UFUNCTION()
	void ForwardOnLocationChanged(const FString& InLocation);

	UFUNCTION()
	void ForwardOnPlaceChanged(AFortPlayerStateAthena* Sender, int32 InPlace);

	UFUNCTION()
	void ForwardOnPlayerNameChanged(AFortPlayerStateAthena* InPlayerState, const FString& InPlayerName);

	UFUNCTION()
	void ForwardOnSquadIdChanged(uint8 InSquadId);

	UFUNCTION()
	void ForwardOnVehicleHealthChanged();

	UFUNCTION()
	void ForwardOnVehicleStateChanged(AFortPlayerPawn* PlayerPawn, AActor* NewVehicle, AActor* OldVehicle);

	UFUNCTION()
	void ForwardOnWeaponChanged(AFortWeapon* InNewWeapon, AFortWeapon* InPrevWeapon);

	UPROPERTY()
	FUniqueNetIdRepl PlayerUID;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> PlayerState;

	UPROPERTY()
	TWeakObjectPtr<AFortPlayerPawn> CachedPlayerPawn;

};

