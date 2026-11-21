// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Animation/AnimInputs/FortAnimInput_SlopeInfo.h"
#include "Animation/FortAnimInputs.h"
#include "Animation/FortAnimInstance.h"
#include "Animation/FortAnimTypes.h"
#include "Animation/FortPlayMontageForGameplayTagQueryInterface.h"
#include "Customization/GameplayTagAnimation.h"
#include "FortCombatTypes.h"
#include "FortCustomPartTypeEnum.h"
#include "FortGender.h"
#include "FortVehicleTypes.h"
#include "CustomCharacterPartAnimInstance.generated.h"

class AFortPlayerPawn;
class AFortWeapon;
class UAnimMontage;
class UCustomCharacterPart;
class UFortAnimInputEvent_CharacterCustomization;
class UFortPlayerAnimInstance;
class UFortPlayerAnimationInterface;
class UFrontendAnimInstance;
class USkeletalMeshComponent;
class USkeletalMeshComponentBudgeted;
enum class EFortDayPhase : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FCharacterCustomizationFinished);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance : public UFortAnimInstance, public IFortPlayMontageForGameplayTagQueryInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Cosmetic Tags")
	bool BackpackItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags);

	UFUNCTION(BlueprintPure, Category="Cosmetic Tags")
	bool CharacterItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags);

	UFUNCTION(BlueprintPure, Category="Custom Character")
	void CheckForBackbling(bool& bIsWearingBackbling, UPARAM(DisplayName="Is Backbling A Cape") bool& bIsBackblingACape, bool& bIsBackblingLong, float LongBackblingThreshold = 50.000000f) const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	void CheckForTail(bool& bHasTail) const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	USkeletalMeshComponent* FindChildCommponentFromAttachSocket(USkeletalMeshComponent* Parent, bool bIncludeAllDescendants, FName AttachSocket) const;

	UFUNCTION(BlueprintPure, Category="Custom Character", meta=(DeprecatedFunction, DeprecationMessage="Character parts can be associated with Player Pawns, HexMapPlayerMarkers (found in the lobby), and Player Mannequins, so using a FortPlayerPawn should be done with extreme care.  You can still do that by calling \"Get Owning Actor\" and casting it to the appropriate type(s)."))
	virtual AFortPlayerPawn* GetAssociatedPlayerPawn() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	virtual const EFortCustomPartType::Type GetCharacterPartType() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	UFortPlayerAnimationInterface* GetOwnerAnimationInterface() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	float GetOwnerDirection() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	UFortPlayerAnimInstance* GetOwnerFortPlayerAnimInstance() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	UFrontendAnimInstance* GetOwnerFrontEndAnimInstance() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	EFortCustomGender::Type GetOwnerGender() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	USkeletalMeshComponent* GetOwnerSkeletalMeshComponent() const;

	UFUNCTION(BlueprintPure, Category="Custom Character", meta=(DeprecatedFunction, DeprecationMessage="Please use PawnVelocityZ instead."))
	float GetOwnerZVelocity() const;

	UFUNCTION(BlueprintPure, Category="Custom Character")
	USkeletalMeshComponent* GetPartSkeletalMeshComponent() const;

	UFUNCTION(BlueprintPure, Category="Cosmetic Tags")
	bool GliderItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags, bool bRequiresOpened);

	UFUNCTION(BlueprintPure, Category="Wave Utility", meta=(AdvancedDisplay="3", CPP_Default_Amplitudes="1.000000,1.000000,1.000000", CPP_Default_Frequencies="1.000000,1.000000,1.000000", CPP_Default_Offsets="0.000000,45.000000,90.000000", CPP_Default_bUseNoise="false", CPP_Default_Min, CPP_Default_Max))
	FRotator MakeWaveRotator(FRotator Amplitudes, FRotator Frequencies, FRotator Offsets, bool bUseNoise, FVector Min, FVector Max);

	UFUNCTION(BlueprintPure, Category="Wave Utility", meta=(AdvancedDisplay="3", CPP_Default_Amplitude="1.000000", CPP_Default_Frequency="1.000000", CPP_Default_Offset="0.000000", CPP_Default_bUseNoise="false", CPP_Default_MinMax))
	float MakeWaveScalar(float Amplitude, float Frequency, float Offset, bool bUseNoise, FVector2D MinMax);

	UFUNCTION(BlueprintPure, Category="Wave Utility", meta=(AdvancedDisplay="3", CPP_Default_Amplitudes="1.000000,1.000000,1.000000", CPP_Default_Frequencies="1.000000,1.000000,1.000000", CPP_Default_Offsets="0.000000,45.000000,90.000000", CPP_Default_bUseNoise="false", CPP_Default_Min, CPP_Default_Max))
	FVector MakeWaveVector(FRotator Amplitudes, FRotator Frequencies, FRotator Offsets, bool bUseNoise, FVector Min, FVector Max);

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginBaseballSliding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginCrouching();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginFalling();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginJumping();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginKneeSliding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginPlayingEmote();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginSkydiving();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginSliding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginTargeting();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCharacterAndPickaxeCustomizationLoaded(const USkeletalMeshComponent* CustomBaseMesh, const TArray<UCustomCharacterPart*>& CustomParts, const TArray<USkeletalMeshComponentBudgeted*>& CustomMeshParts);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCharacterCustomizationLoaded(const USkeletalMeshComponent* CustomBaseMesh, const TArray<UCustomCharacterPart*>& CustomParts, const TArray<USkeletalMeshComponentBudgeted*>& CustomMeshParts);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDayPhaseChanged(EFortDayPhase CurrentDayPhase, EFortDayPhase PreviousDayPhase, bool bAtCreation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndBaseballSliding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndCrouching();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndFalling();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndJumping();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndKneeSliding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndPlayingEmote();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndSkydiving();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndSliding();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndTargeting();

	UFUNCTION(BlueprintImplementableEvent, Category="Grind Rails")
	void OnEnterGrindRail();

	UFUNCTION(BlueprintImplementableEvent, Category="Grind Rails")
	void OnExitGrindRail();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNotifyPartsStarted(FName Context);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNotifyPartsStopped(FName Context);

	UFUNCTION(BlueprintImplementableEvent)
	void OnParachuteClosed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParachuteOpened();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayMontageFromGameplayTagQuery(const FGameplayTagQuery& MatchingQuery, UAnimMontage* MontagePlaying);

	UFUNCTION(BlueprintImplementableEvent)
	void OnWeaponChanged();

	UFUNCTION(BlueprintPure, Category="Cosmetic Tags")
	bool PickaxeItemDefinitionHasAnyMetaTag(const TArray<FGameplayTag>& Tags, bool bRequiresEquipped);

	UFUNCTION(BlueprintImplementableEvent)
	void PreDestruction();

	UPROPERTY(BlueprintAssignable)
	FCharacterCustomizationFinished CharacterCustomizationFinished;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay")
	TObjectPtr<AFortWeapon> CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay")
	uint8 bUsesDayPhaseChange : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Optimizations")
	uint8 bIgnoreSignificanceManagerAndAlwaysTick : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character")
	uint8 bHideUntilFirstAnimationUpdate : 1;

	UPROPERTY(Transient)
	uint8 bUnhideOnNextUpdate : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Gameplay")
	uint8 bCanPlayCustomAnimations : 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Character")
	uint8 bUpdateOwnerAnimInputProperty : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsRiding : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSkyDiving : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsParachuteOpened : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSkydiveDiveMode : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSkydiveFloating : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsCrouching : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSprinting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsAccelerating2D : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsMoving2D : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsBackpedaling : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsUsingJetpack : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	bool bGoopJumpExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSlopeSliding : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSurfaceSwimming : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsWaterJump : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsSwimSprinting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsPlayingEmote : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsPlayingMeleeAnim : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsPlayingFullBodySlotInFrontEnd : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsInFrontEnd : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsInVehicle : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsValetDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character")
	uint8 bIsValetPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsInShoppingCart : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsInCannon : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsTargeting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsTargetingConsumableThrow : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsCrouchSprinting : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsDBNO : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsOnGround : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsLandingPredicted : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsInVehicleSeat : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bVehicleSeatForcesCrouch : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsFerretVehicleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsFerretVehiclePassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsGolfCartVehicleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsGolfCartVehicleFrontPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsGolfCartVehicleBackPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsAntelopeVehicleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsAntelopeVehiclePassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsMotorcycleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsMotorcyclePassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bHasMotorcyclePassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsJackalVehicleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsOctopusVehicleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsOstrichVehicleDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsOstrichVehicleGunner : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsMeatballDriver : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsMeatballPassenger : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsDBNOCarrying : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsDBNOCarried : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	uint8 bIsTacticalSprinting : 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Character")
	uint8 bOverrideRBANSimSpaceInFrontEnd : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	ESlotEnvironmentExposure VehicleSlotExposure;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Animation")
	FGameplayTagAnimations GameplayTagAnimations;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	float CrouchingWithRigidBodyEnabled;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	float RidingSpeed2D;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	int32 CurrentLOD;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SkydivingExternalForce")
	FFortAnimInput_SkydivingExternalForce SkydivingExternalForceInput;

	UPROPERTY(BlueprintReadOnly, Category="Slope")
	FFortAnimInput_SlopeInfo SlopeInfoInput;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Transient, Category="Character|Glider", meta=(EditCondition="bUpdateOwnerAnimInputProperty"))
	EGliderType PlayerGliderType;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Weapon")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponCoreAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Grind Rails")
	uint8 bIsOnGrindRail : 1;

private:
	UPROPERTY(Transient)
	uint8 bRegisteredForDayPhaseChange : 1;

	UPROPERTY(Transient)
	TEnumAsByte<EFortCustomPartType::Type> PartType;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<USkeletalMeshComponent> OwnerSkeletalMeshComponent;

	UPROPERTY(Transient)
	UFortAnimInputEvent_CharacterCustomization* PendingCustomizationFinishedEvent;

	UPROPERTY(Transient)
	UFortAnimInputEvent_CharacterCustomization* PendingPickaxeCustomizationFinishedEvent;

};

