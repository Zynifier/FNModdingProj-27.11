// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MusicKey.h"
#include "FMCoreMusicManagerComponent.generated.h"

enum class EMusicKey : uint8;
enum class EMusicKeyMode : uint8;

USTRUCT(BlueprintType)
struct FFMCoreTimeSignature
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMCoreTimeSignature")
	int32 Numerator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FMCoreTimeSignature")
	int32 Denominator;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class FMCORERUNTIME_API UFMCoreMusicManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeyChanged, EMusicKey, CurrentKey);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModeChanged, EMusicKeyMode, CurrentMode);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTempoChanged, int32, CurrentTempo);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeSignatureChanged, FFMCoreTimeSignature, TimeSignature);

public:
	UFUNCTION(BlueprintPure)
	void GetCurrentAudioState(EMusicKey& OutKey, EMusicKeyMode& OutKeyMode, int32& OutTempo) const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	EMusicKey GetCurrentKey() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	EMusicKeyMode GetCurrentKeyMode() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	int32 GetCurrentTempo() const;

	UFUNCTION(BlueprintPure, meta=(BlueprintGetter))
	FFMCoreTimeSignature GetCurrentTimeSignature() const;

	UFUNCTION(BlueprintCallable)
	void TriggerKeyChange(EMusicKey InKey);

	UFUNCTION(BlueprintCallable)
	void TriggerModeChange(EMusicKeyMode InMode);

	UFUNCTION(BlueprintCallable)
	void TriggerTempoChange(int32 Bpm);

	UFUNCTION(BlueprintCallable)
	void TriggerTimeSignatureChange(int32 Numerator, int32 Denominator);

	UPROPERTY(BlueprintAssignable)
	FOnTempoChanged OnTempoChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnKeyChanged OnKeyChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnModeChanged OnModeChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnTimeSignatureChanged OnTimeSignatureChanged;

	UPROPERTY(EditAnywhere, Category="FMCoreMusicManagerComponent")
	EMusicKey StartingKey;

	UPROPERTY(EditAnywhere, Category="FMCoreMusicManagerComponent")
	EMusicKeyMode StartingMode;

	UPROPERTY(EditAnywhere, Category="FMCoreMusicManagerComponent")
	int32 StartingTempo;

	UPROPERTY(EditAnywhere, Category="FMCoreMusicManagerComponent")
	int32 StartingTimeSignatureNumerator;

	UPROPERTY(EditAnywhere, Category="FMCoreMusicManagerComponent")
	int32 StartingTimeSignatureDenominator;

private:
	UFUNCTION()
	void OnRep_ServerKeyChanged();

	UFUNCTION()
	void OnRep_ServerModeChanged();

	UFUNCTION()
	void OnRep_ServerTempoChanged();

	UFUNCTION()
	void OnRep_ServerTimeSignatureChanged();

	UPROPERTY(BlueprintGetter=GetCurrentKey, Category="FMCoreMusicManagerComponent", meta=(AllowPrivateAccess="true"))
	EMusicKey CurrentKey;

	UPROPERTY(BlueprintGetter=GetCurrentKeyMode, Category="FMCoreMusicManagerComponent", meta=(AllowPrivateAccess="true"))
	EMusicKeyMode CurrentMode;

	UPROPERTY(BlueprintGetter=GetCurrentTempo, Category="FMCoreMusicManagerComponent", meta=(AllowPrivateAccess="true"))
	int32 CurrentTempo;

	UPROPERTY(BlueprintGetter=GetCurrentTimeSignature, Category="FMCoreMusicManagerComponent", meta=(AllowPrivateAccess="true"))
	FFMCoreTimeSignature CurrentTimeSignature;

	UPROPERTY(ReplicatedUsing=OnRep_ServerKeyChanged)
	EMusicKey ServerKey;

	UPROPERTY(ReplicatedUsing=OnRep_ServerModeChanged)
	EMusicKeyMode ServerMode;

	UPROPERTY(ReplicatedUsing=OnRep_ServerTempoChanged)
	int32 ServerTempo;

	UPROPERTY(ReplicatedUsing=OnRep_ServerTimeSignatureChanged)
	FFMCoreTimeSignature ServerTimeSignature;

};

